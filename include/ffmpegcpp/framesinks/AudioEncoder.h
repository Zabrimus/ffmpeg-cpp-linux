#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/std.h>
#include <ffmpegcpp/framesinks/AudioFrameSink.h>
#include <ffmpegcpp/codecs/AudioCodec.h>
#include <ffmpegcpp/ConvertedAudioProcessor.h>
#include <ffmpegcpp/AudioFormatConverter.h>
#include <ffmpegcpp/muxing/Muxer.h>
#include <ffmpegcpp/muxing/OutputStream.h>
#include <ffmpegcpp/framesinks/OneInputFrameSink.h>

namespace ffmpegcpp
{
	class AudioEncoder : public AudioFrameSink, public ConvertedAudioProcessor, public FrameWriter
	{
	public:
		AudioEncoder(AudioCodec* codec, Muxer* muxer);
		AudioEncoder(AudioCodec* codec, Muxer* muxer, int bitRate);
		~AudioEncoder() override;

		FrameSinkStream* CreateStream() override;
		void WriteFrame(int streamIndex, AVFrame* frame, StreamData* metaData) override;
		void Close(int streamIndex) override;

		void WriteConvertedFrame(AVFrame* frame) override;

		bool IsPrimed() override;

	private:

		void OpenLazily(AVFrame* frame, StreamData* metaData);

		void CleanUp();

		void PollCodecForPackets();

		OutputStream* output;

		AudioCodec* closedCodec;

		AudioFormatConverter *formatConverter = nullptr;
		OpenCodec* codec = nullptr;
		AVPacket* pkt = nullptr;

		OneInputFrameSink* oneInputFrameSink = nullptr;

		int frameNumber = 0;

		int finalBitRate = -1;
	};
}

