#pragma once

#define FFMPEG_CPP_VERSION_MAJOR 1
#define FFMPEG_CPP_VERSION_MINOR 0

#if defined(__linux__)
    #define FFPMPEG_CPP_SYSTEM_LINUX
#else
    #error This operating system is not supported
#endif

#include "config_impl.hpp"