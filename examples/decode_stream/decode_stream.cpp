#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <ffmpegcpp/ffmpegcpp.h>

using namespace std;
using namespace ffmpegcpp;

#define STREAM_INPUT "tcp://127.0.0.1:5000"

using namespace cv;

class StreamSink : public VideoFrameSink, public FrameWriter
{
public:
	StreamSink()
	{
	}

	FrameSinkStream *CreateStream()
	{
		stream = new FrameSinkStream(this, 0);
		return stream;
	}

	virtual void WriteFrame(int streamIndex, AVFrame *frame, StreamData *streamData)
	{
		++frameNumber;

		cv::Mat mat(480, 640, CV_8UC3);

		avframeToMat(frame, mat);

		cv::imshow("frame", mat);
		cv::waitKey(1);
	}

	void avframeToMat(const AVFrame *frame, Mat &image)
	{
		int width = frame->width;
		int height = frame->height;

		// Allocate the opencv mat and store its stride in a 1-element array
		if (image.rows != height || image.cols != width || image.type() != CV_8UC3)
			image = Mat(height, width, CV_8UC3);
		int cvLinesizes[1];
		cvLinesizes[0] = image.step1();

		// Convert the colour format and write directly to the opencv matrix
		SwsContext *conversion = sws_getContext(width, height, (AVPixelFormat)frame->format, width, height, AV_PIX_FMT_BGR24, SWS_FAST_BILINEAR, NULL, NULL, NULL);
		sws_scale(conversion, frame->data, frame->linesize, 0, height, &image.data, cvLinesizes);
		sws_freeContext(conversion);
	}

	virtual void Close(int streamIndex)
	{
		delete stream;
	}

	virtual bool IsPrimed()
	{
		// Return whether we have all information we need to start writing out data.
		// Since we don't really need any data in this use case, we are always ready.
		// A container might only be primed once it received at least one frame from each source
		// it will be muxing together (see Muxer.cpp for how this would work then).
		return true;
	}

private:
	char fileNameBuffer[1024];
	int frameNumber = 0;
	FrameSinkStream *stream;
};

void print_info(Demuxer *demuxer)
{
	ContainerInfo info = demuxer->GetInfo();

	cout << "Input " << info.format->name << " from '" << STREAM_INPUT << "'" << endl;
	cout << "Bitrate: " << info.bitRate << endl;

	cout << "Video streams: [" << info.videoStreams.size() << "]" << endl;
	for (int i = 0; i < info.videoStreams.size(); i++)
	{
		VideoStreamInfo stream = info.videoStreams[i];
		cout 	<< "Resolution: " << stream.width << "x" << stream.height << "\n"
				<< "Codec: " << stream.codec->name << "\n"
				<< "Pixel format: " << stream.formatName << "\n"
				<< "Bitrate: " << stream.bitRate << "\n"
				<< "FPS: " << ((float)stream.frameRate.num / (float)stream.frameRate.den) << "\n"
				<< "Time base: " << stream.timeBase.num << "/" << stream.timeBase.den << endl;
	}
}

int main()
{
	int frames = 0;
	// This example will decode a video stream from a container and output it as raw image data, one image per frame.
	try
	{
		// Load this container file so we can extract video from it.
		Demuxer *demuxer = new Demuxer(STREAM_INPUT);

		// print_info(demuxer);

		// Create a file sink that will just output the raw frame data in one PGM file per frame.
		StreamSink *streamSink = new StreamSink();

		// tie the file sink to the best video stream in the input container.
		demuxer->DecodeBestVideoStream(streamSink);

		// Prepare the output pipeline. This will push a small amount of frames to the file sink until it IsPrimed returns true.
		demuxer->PreparePipeline();
		// demuxer->Step();


		// Push all the remaining frames through.
		while (!demuxer->IsDone())
		{
			print_info(demuxer);
			demuxer->Step();
			cout << "\x1b[H\x1b[J";
		}

		// done
		cv::destroyAllWindows();
		delete demuxer;
		delete streamSink;
	}
	catch (FFmpegException e)
	{
		cerr << "Exception caught: " << e.what() << endl;
		throw e;
	}

	cout << "Decoding complete!" << endl;
	cout << "Press any key to continue..." << endl;

	getchar();
}
