#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/codecs/Codec.h>
#include <ffmpegcpp/muxing/OutputStream.h>
#include <ffmpegcpp/muxing/Muxer.h>


namespace ffmpegcpp
{
	class AudioOutputStream : public OutputStream
	{
	public:

		AudioOutputStream(Muxer* muxer, Codec* codec);

		void OpenStream(AVStream* stream, int containerFlags) override;

		void WritePacket(AVPacket* pkt, OpenCodec* openCodec) override;

		bool IsPrimed() override;

	protected:

		void PreparePacketForMuxer(AVPacket* pkt) override;

	private:

		void LazilyInitialize(OpenCodec* openCodec);

		AVStream* stream;

		bool initialized = false;

		AVRational codecTimeBase;
	};
}
