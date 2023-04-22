#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/sources/InputSource.h>
#include <ffmpegcpp/sources/Demuxer.h>

namespace ffmpegcpp
{
	class RawAudioFileSource : public InputSource
	{
	public:

		RawAudioFileSource(const char* fileName, const char* inputFormat, int sampleRate, int channels, FrameSink* frameSink);
		~RawAudioFileSource() override;

		void PreparePipeline() override;
		bool IsDone() override;
		void Step() override;

	private:

		void CleanUp();

		Demuxer* demuxer = nullptr;
	};


}
