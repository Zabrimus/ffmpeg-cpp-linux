#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/framesinks/FrameSink.h>
#include <ffmpegcpp/sources/InputSource.h>

namespace ffmpegcpp
{
	// EncodedFileSource takes a file that is already encoded but not in a container (ie .mp3, .h264)
	// and feeds it to the system.
	class EncodedFileSource : public InputSource
	{

	public:
		EncodedFileSource(const char* inFileName, AVCodecID codecId, FrameSink* output);
		EncodedFileSource(const char* inFileName, const char* codecName, FrameSink* output);
		~EncodedFileSource() override;

		void PreparePipeline() override;
		bool IsDone() override;
		void Step() override;

	private:

		void CleanUp();

		bool done = false;

		FrameSinkStream* output;
		
		AVCodecParserContext* parser = nullptr;

		const AVCodec* codec;
		AVCodecContext* codecContext = nullptr;

		int bufferSize;

		AVFrame* decoded_frame = nullptr;
		AVPacket* pkt = nullptr;
		uint8_t* buffer = nullptr;

		FILE* file;

		void Init(const char* inFileName, const AVCodec *codec, FrameSink* output);

		void Decode(AVPacket *packet, AVFrame* targetFrame);

		AVRational timeBaseCorrectedByTicksPerFrame;

		StreamData* metaData = nullptr;
	};
}
