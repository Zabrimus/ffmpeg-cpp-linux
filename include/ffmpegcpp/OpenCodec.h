#pragma once

#include "ffmpeg.h"

namespace ffmpegcpp
{
	class OpenCodec
	{
	public:

		explicit OpenCodec(AVCodecContext* openCodecContext);
		~OpenCodec();

		AVCodecContext* GetContext();

	private:

		AVCodecContext* context;
	};


}
