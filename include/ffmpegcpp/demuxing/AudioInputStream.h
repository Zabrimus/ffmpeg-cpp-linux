#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/demuxing/InputStream.h>
#include <ffmpegcpp/framesinks/AudioFrameSink.h>

namespace ffmpegcpp
{
	class AudioInputStream : public InputStream
	{

	public:

		AudioInputStream(AVFormatContext* format, AVStream* stream);
		~AudioInputStream();

		void AddStreamInfo(ContainerInfo* info) override;

	protected:

		void ConfigureCodecContext() override;
	};
}
