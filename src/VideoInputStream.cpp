#include <ffmpegcpp/demuxing/VideoInputStream.h>
#include <ffmpegcpp/FFmpegException.h>
#include <ffmpegcpp/CodecDeducer.h>

namespace ffmpegcpp
{
	VideoInputStream::VideoInputStream(AVFormatContext* format, AVStream* stream)
		: InputStream(format, stream)
	{
	}

	VideoInputStream::~VideoInputStream() = default;

	void VideoInputStream::ConfigureCodecContext()
	{
	}

	void VideoInputStream::AddStreamInfo(ContainerInfo* containerInfo)
	{
		VideoStreamInfo info;

		info.id = stream->id; // the layout of the id's depends on the container format - it doesn't always start from 0 or 1!

		AVRational overrideFrameRate;
		overrideFrameRate.num = 0;

		AVRational tb = overrideFrameRate.num ? av_inv_q(overrideFrameRate) : stream->time_base;
		AVRational fr = overrideFrameRate;
		if (!fr.num) fr = av_guess_frame_rate(format, stream, nullptr);

		StreamData* metaData = new StreamData();
		info.timeBase = tb;
		info.frameRate = fr;

		AVCodecContext* codecContext = avcodec_alloc_context3(nullptr);
        if (!codecContext) {
            throw FFmpegException("Failed to allocate temporary codec context.");
        }

		int ret = avcodec_parameters_to_context(codecContext, stream->codecpar);
		if (ret < 0) {
			avcodec_free_context(&codecContext);
			throw FFmpegException("Failed to read parameters from stream");
		}

		info.bitRate = CalculateBitRate(codecContext);

		const AVCodec *codec = CodecDeducer::DeduceDecoder(codecContext->codec_id);
		info.codec = codec;

		info.format = codecContext->pix_fmt;
		info.formatName = av_get_pix_fmt_name(info.format);

		info.width = codecContext->width;
		info.height = codecContext->height;

		avcodec_free_context(&codecContext);

		containerInfo->videoStreams.push_back(info);
	}
}

