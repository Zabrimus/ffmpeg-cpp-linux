#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/demuxing/InputStream.h>
#include <ffmpegcpp/framesinks/VideoFrameSink.h>
#include <ffmpegcpp/info/VideoStreamInfo.h>

namespace ffmpegcpp
{
	class VideoInputStream : public InputStream
	{

	public:

		VideoInputStream(AVFormatContext* format, AVStream* stream);
		~VideoInputStream();

		void AddStreamInfo(ContainerInfo* info);

	protected:

		virtual void ConfigureCodecContext();

	};
}
