#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/std.h>
#include <ffmpegcpp/demuxing/AudioInputStream.h>
#include <ffmpegcpp/demuxing/VideoInputStream.h>
#include <ffmpegcpp/demuxing/InputStream.h>
#include <ffmpegcpp/sources/InputSource.h>
#include <ffmpegcpp/info/ContainerInfo.h>

namespace ffmpegcpp
{
	class Demuxer : public InputSource
	{
	public:

		Demuxer(const char* fileName);
		Demuxer(const char* fileName, AVInputFormat* inputFormat, AVDictionary *inputFormatOptions);
		~Demuxer();

		void DecodeBestAudioStream(FrameSink* frameSink);
		void DecodeBestVideoStream(FrameSink* frameSink);

		void DecodeAudioStream(int streamId, FrameSink* frameSink);
		void DecodeVideoStream(int streamId, FrameSink* frameSink);

		virtual void PreparePipeline();
		virtual bool IsDone();
		virtual void Step();

		ContainerInfo GetInfo();
		int GetFrameCount(int streamId);

		const char* GetFileName();

	private:

		bool done = false;

		const char* fileName;

		InputStream* GetInputStream(int index);
		InputStream* GetInputStreamById(int streamId);

		//std::vector<StreamInfo> GetStreamInfo(AVMediaType mediaType);
		//StreamInfo CreateInfo(int streamIndex, AVStream* stream, AVCodec* codec);

		InputStream** inputStreams = nullptr;

		AVFormatContext* containerContext = nullptr;
		AVPacket* pkt = nullptr;

		void DecodePacket();

		void CleanUp();
	};
}
