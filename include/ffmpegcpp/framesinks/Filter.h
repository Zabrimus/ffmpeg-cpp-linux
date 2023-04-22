#pragma once

#include <ffmpegcpp/ffmpeg.h>
#include <ffmpegcpp/std.h>
#include <ffmpegcpp/framesinks/VideoFrameSink.h>
#include <ffmpegcpp/framesinks/VideoFilterInput.h>

namespace ffmpegcpp
{
	class Filter : public FrameSink, public FrameWriter
	{

	public:

		Filter(const char* filterString, FrameSink* target);
		~Filter() override;

		FrameSinkStream* CreateStream() override;

		void WriteFrame(int streamIndex, AVFrame* frame, StreamData* metaData) override;
		void Close(int streamIndex) override;

		bool IsPrimed() override;

		AVMediaType GetMediaType() override;

	private:

		void CleanUp();

		void ConfigureFilterGraph();
		void DrainInputQueues();
		void PollFilterGraphForFrames();
		void FillArguments(char* args, int argsLength, AVFrame* frame, StreamData* metaData);

		const char* GetBufferName(AVMediaType mediaType);
		const char* GetBufferSinkName(AVMediaType mediaType);

		std::vector<VideoFilterInput*> inputs;
		std::vector<AVFilterContext*> bufferSources;

		AVMediaType targetMediaType;
		FrameSinkStream* target;

		const char* filterString;

		AVFilterGraph *filter_graph = nullptr;
		AVFilterContext *buffersink_ctx = nullptr;
		AVFrame* filt_frame = nullptr;

		bool initialized = false;

		StreamData outputMetaData;
	};


}
