#pragma once

namespace ffmpegcpp
{
	class InputSource
	{
	public:

		virtual ~InputSource() = default;

		virtual void PreparePipeline() = 0;
		virtual bool IsDone() = 0;
		virtual void Step() = 0;

	};
}


