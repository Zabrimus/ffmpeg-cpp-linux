#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/framesinks/VideoFrameSink.h>
#include <ffmpegcpp/codecs/VideoCodec.h>
#include <ffmpegcpp/VideoFormatConverter.h>
#include <ffmpegcpp/muxing/Muxer.h>
#include <ffmpegcpp/framesinks/OneInputFrameSink.h>

namespace ffmpegcpp
{
	class VideoEncoder : public VideoFrameSink, public FrameWriter
	{
	public:
		VideoEncoder(VideoCodec* codec, Muxer* muxer);
		VideoEncoder(VideoCodec* codec, Muxer* muxer, AVPixelFormat format);
		VideoEncoder(VideoCodec* codec, Muxer* muxer, AVRational frameRate);
		VideoEncoder(VideoCodec* codec, Muxer* muxer, AVRational frameRate, AVPixelFormat format);
		~VideoEncoder() override;

		FrameSinkStream* CreateStream() override;

		void WriteFrame(int streamIndex, AVFrame* frame, StreamData* metaData) override;
		void Close(int streamIndex) override;

		bool IsPrimed() override;

	private:

		void OpenLazily(AVFrame* frame, StreamData* metaData);
		void PollCodecForPackets();

		VideoCodec* closedCodec;
		OutputStream* output;

		VideoFormatConverter* formatConverter = nullptr;
		OpenCodec* codec = nullptr;
		AVPacket* pkt = nullptr;

		OneInputFrameSink* oneInputFrameSink = nullptr;

		int frameNumber = 0;

		void CleanUp();

		AVPixelFormat finalPixelFormat = AV_PIX_FMT_NONE;

		AVRational finalFrameRate;
		bool finalFrameRateSet = false;
	};
}

