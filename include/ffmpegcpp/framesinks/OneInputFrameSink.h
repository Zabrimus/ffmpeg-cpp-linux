#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/framesinks/FrameWriter.h>
#include <ffmpegcpp/framesinks/FrameSink.h>

namespace ffmpegcpp
{
	class OneInputFrameSink : public FrameSink
	{
	public:

		OneInputFrameSink(FrameWriter* writer, AVMediaType mediaType);
		~OneInputFrameSink();

		virtual AVMediaType GetMediaType();

		FrameSinkStream* CreateStream();


	private:

		int nStreamsGenerated = 0;

		FrameWriter* writer;

		FrameSinkStream* stream = nullptr;

		AVMediaType mediaType;
	};
}

