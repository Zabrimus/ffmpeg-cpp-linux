#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/std.h>

namespace ffmpegcpp {

	class OutputStream;

	class Muxer
	{
	public:

		explicit Muxer(const char* fileName);
		~Muxer();

		void AddOutputStream(OutputStream* stream);

		void WritePacket(AVPacket* pkt);

		void Close();
		
		bool IsPrimed();

		const AVCodec * GetDefaultVideoFormat();
		const AVCodec * GetDefaultAudioFormat();


	private:

		void Open();
		
		std::vector<OutputStream*> outputStreams;
		std::vector<AVPacket*> packetQueue;

		const AVOutputFormat* containerFormat;

		AVFormatContext* containerContext = nullptr;

		std::string fileName;

		void CleanUp();

		bool opened = false;
	};
}
