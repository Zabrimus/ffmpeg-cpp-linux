#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/info/VideoStreamInfo.h>
#include <ffmpegcpp/info/AudioStreamInfo.h>
#include <ffmpegcpp/std.h>

namespace ffmpegcpp
{
	struct ContainerInfo
	{
		long durationInMicroSeconds;
		float durationInSeconds;
		float start;
		int64_t bitRate;
		const AVInputFormat* format;

		std::vector<VideoStreamInfo> videoStreams;
		std::vector<AudioStreamInfo> audioStreams;
	};


}
