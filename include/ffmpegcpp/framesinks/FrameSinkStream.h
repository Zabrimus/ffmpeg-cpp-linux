#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/framesinks/FrameWriter.h>
#include <ffmpegcpp/demuxing/StreamData.h>

namespace ffmpegcpp
{
	class FrameSinkStream
	{
	public:

		FrameSinkStream(FrameWriter* frameSink, int streamIdx);

		void WriteFrame(AVFrame* frame, StreamData* metaData);

		void Close();

		bool IsPrimed();

	private:

		FrameWriter* frameSink;
		int streamIndex;
	};
}
