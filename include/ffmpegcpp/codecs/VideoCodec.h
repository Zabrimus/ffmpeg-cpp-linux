#pragma once

#include <ffmpegcpp/codecs/Codec.h>
#include <ffmpegcpp/OpenCodec.h>

namespace ffmpegcpp
{

	class VideoCodec : public Codec
	{
	public:

		explicit VideoCodec(const char* codecName);
		explicit VideoCodec(AVCodecID codecId);
		~VideoCodec() override;

		OpenCodec* Open(int width, int height, AVRational* frameRate, AVPixelFormat format);

		// This maps to the qscale parameter so should be in the range [0,31].
		void SetQualityScale(int qscale);

		bool IsPixelFormatSupported(AVPixelFormat format);
		bool IsFrameRateSupported(AVRational* frameRate);

		AVPixelFormat GetDefaultPixelFormat();
		AVRational GetClosestSupportedFrameRate(AVRational frameRate);

	};


}