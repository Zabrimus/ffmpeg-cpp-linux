#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/std.h>
#include <ffmpegcpp/OpenCodec.h>

namespace ffmpegcpp
{

	class Codec
	{
	public:

		explicit Codec(const char* codecName);
		explicit Codec(AVCodecID codecId);
		virtual ~Codec();

		void SetOption(const char* name, const char* value);
		void SetOption(const char* name, int value);
		void SetOption(const char* name, double value);

		void SetGenericOption(const char* name, const char* value);

		void SetGlobalContainerHeader(); // used by the Muxer for configuration purposes

	protected:

		AVCodecContext* codecContext = nullptr;

		OpenCodec* Open();

	private:

		void CleanUp();

		AVCodecContext* LoadContext(const AVCodec *codec);

		bool opened = false;
	};
}
