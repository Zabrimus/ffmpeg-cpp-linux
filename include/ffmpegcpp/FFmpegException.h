#pragma once

#include "ffmpeg.h"

#include "std.h"

namespace ffmpegcpp
{
	class FFmpegException : std::exception
	{

	public:

		explicit FFmpegException(const std::string & error);

		explicit FFmpegException(const std::string & error, int returnValue);

		char const* what() const noexcept override
		{
			return (const char *)error;
		}


	private:

		char error[AV_ERROR_MAX_STRING_SIZE];
	};
}