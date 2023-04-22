#include <ffmpegcpp/framesinks/OneInputFrameSink.h>
#include <ffmpegcpp/FFmpegException.h>

using namespace std;

namespace ffmpegcpp
{

	OneInputFrameSink::OneInputFrameSink(FrameWriter* writer, AVMediaType mediaType)
	{
		this->writer = writer;
		this->mediaType = mediaType;
	}

	FrameSinkStream* OneInputFrameSink::CreateStream()
	{
		++nStreamsGenerated;
		if (nStreamsGenerated > 1)
		{
			throw FFmpegException("This frame sink only supports one input");
		}
		stream = new FrameSinkStream(writer, 0);
		return stream;
	}

	OneInputFrameSink::~OneInputFrameSink()
	{
        delete stream;
	}

	AVMediaType OneInputFrameSink::GetMediaType()
	{
		return mediaType;
	}
}

