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
		~OneInputFrameSink() override;

		AVMediaType GetMediaType() override;

		FrameSinkStream* CreateStream() override;


	private:

		int nStreamsGenerated = 0;

		FrameWriter* writer;

		FrameSinkStream* stream = nullptr;

		AVMediaType mediaType;
	};
}

