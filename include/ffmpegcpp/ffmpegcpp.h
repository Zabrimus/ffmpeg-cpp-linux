#pragma once

#include "ffmpeg.h"

#include <ffmpegcpp/muxing/Muxer.h>

#include <ffmpegcpp/sources/Demuxer.h>
#include <ffmpegcpp/sources/RawAudioFileSource.h>
#include <ffmpegcpp/sources/RawAudioDataSource.h>
#include <ffmpegcpp/sources/RawVideoFileSource.h>
#include <ffmpegcpp/sources/RawVideoDataSource.h>
#include <ffmpegcpp/sources/EncodedFileSource.h>

#include <ffmpegcpp/framesinks/VideoEncoder.h>
#include <ffmpegcpp/framesinks/AudioEncoder.h>
#include <ffmpegcpp/framesinks/Filter.h>

#include <ffmpegcpp/codecs/AudioCodec.h>
#include <ffmpegcpp/codecs/Codec.h>
#include <ffmpegcpp/codecs/H264NVEncCodec.h>
#include <ffmpegcpp/codecs/H265NVEncCodec.h>
#include <ffmpegcpp/codecs/JPGCodec.h>
#include <ffmpegcpp/codecs/PNGCodec.h>
#include <ffmpegcpp/codecs/VP9Codec.h>

#include <ffmpegcpp/FFmpegException.h>