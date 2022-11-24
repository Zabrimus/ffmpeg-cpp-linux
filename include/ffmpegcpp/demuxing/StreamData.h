#pragma once

#include <ffmpegcpp/ffmpeg.h>

namespace ffmpegcpp
{
	struct StreamData
	{
		AVMediaType type;

		AVRational timeBase;
		AVRational frameRate;
	};
}