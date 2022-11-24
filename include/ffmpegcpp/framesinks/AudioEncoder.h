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
		virtual ~AudioEncoder();

		FrameSinkStream* CreateStream();
		void WriteFrame(int streamIndex, AVFrame* frame, StreamData* metaData);
		void Close(int streamIndex);

		virtual void WriteConvertedFrame(AVFrame* frame);

		bool IsPrimed();

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

