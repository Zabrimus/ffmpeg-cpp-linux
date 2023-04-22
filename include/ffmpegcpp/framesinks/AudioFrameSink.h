#pragma once

#include <ffmpegcpp/framesinks/FrameSink.h>

namespace ffmpegcpp
{
	class AudioFrameSink : public FrameSink
	{
	public:

		AVMediaType GetMediaType() override
		{
			return AVMEDIA_TYPE_AUDIO;
		}

		~AudioFrameSink() override = default;
	};
}
