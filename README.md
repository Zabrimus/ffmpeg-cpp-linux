# ffmpeg-cpp-linux

:warning: FORKED FROM [Raveler/ffmpeg-cpp](https://github.com/Raveler/ffmpeg-cpp)

[![C/C++ CI](https://github.com/galla15/ffmpeg-cpp-linux/actions/workflows/c-cpp.yml/badge.svg?branch=master&event=workflow_run)](https://github.com/galla15/ffmpeg-cpp-linux/actions/workflows/c-cpp.yml)\
[![C/C++ CI](https://github.com/galla15/ffmpeg-cpp-linux/actions/workflows/c-cpp.yml/badge.svg?branch=master&event=push)](https://github.com/galla15/ffmpeg-cpp-linux/actions/workflows/c-cpp.yml)

# ffmpeg-cpp
A clean C++ wrapper around the ffmpeg libraries which can be used in any C++ project or C# project (with DllImport or CLR). Makes the most commonly used functionality of FFmpeg easily available for any C++ projects with an easy-to-use interface. The full power of FFmpeg compacted in 10 lines of C++ code: if this sounds useful to you, read on!

# Installation

## Dependencies

The project library depends on multiple *libav* components that should be installed before attempting to build the library.

```bash
sudo apt install -y libavcodec-dev libavformat-dev libavutil-dev libavdevice-dev libavfilter-dev
```

The [*decode_stream*](examples/decode_stream/decode_stream.cpp) needs two more libraries.

```bash
sudo apt install -y libopencv-dev libswscale-dev
```

## Build

The library can be built manually like every *cmake* project or through the build script *build.sh*.

```bash
Build the ffmpeg library and example applications

Syntax: ./build.sh [-a|c|e|l|h|i]
a     Build all
c     Clean build directory
e     Build examples
l     Build library only
h     Help
i     Install library.(Default path: /usr/local/)

Examples:
./build.sh -a     Builds all
```

The examples built will be under *build/apps*.

# Usage

There are multiple [example projects](examples/) included in the solution. Check out the [demo-project](examples/demo/) for a thorough exploration of the features (demuxing, decoding, filtering, encoding, muxing).

If you want to use it in an other project, you must install the library [see](#build) and then you can use pck-config in your other project to include the library. There are 2 macro defined:

- FFMPEGCPP_INCLUDE_DIRS: gives the path to the directory of library headers
- FFMPEGCPP_LIBS: give the path to the library for the linker

```cmake
# in CMakeLists.txt
...

find_package(FFMPEGCPP REQUIRED)

...

include_directories(${FFMPEGCPP_INCLUDE_DIRS})

...

target_link_libraries(${PROJECT_NAME} ${FFMPEGCPP_LIBS} ...)
```

## Decode stream app

This app was added by myself in order to show how you can open and display a tcp stream (e.g. coming from a camera).
There is bash script, called *stream_srv.sh*, you need to launch to create a tcp stream before launching the *decode_stream* app. The *decode_stream* is not built by default cause it have additional dependencies [see](#dependencies). To build it just go to the *build* folder and perform the following commands.

```bash
cd build
cmake -DBUILD_DECODE_STREAM=ON ..
make
```

## C++

To give you an idea, this code will load a video stream from a container, filter it, and write it back out to another container:

```C++
// Create a muxer that will output the video as MP4.
Muxer* muxer = new Muxer("filtered_video.mp4");

// Create a MPEG2 codec that will encode the raw data.
VideoCodec* codec = new VideoCodec(AV_CODEC_ID_MPEG2VIDEO);

// Create an encoder that will encode the raw audio data using the codec specified above.
// Tie it to the muxer so it will be written to file.
VideoEncoder* encoder = new VideoEncoder(codec, muxer);

// Create a video filter and do some funny stuff with the video data.
Filter* filter = new Filter("scale=640:150,transpose=cclock,vignette", encoder);

// Load a container. Pick the best video stream container in the container
// And send it to the filter.
Demuxer* demuxer = new Demuxer("big_buck_bunny.mp4");
demuxer->DecodeBestVideoStream(filter);

// Prepare the output pipeline.
// This will decode a small amount of frames so the pipeline can configure itself.
demuxer->PreparePipeline();

// Push all the remaining frames through.
while (!demuxer->IsDone())
{
	demuxer->Step();
}
		
// Save everything to disk by closing the muxer.
muxer->Close();
```

# Why?

I developed this project to be able to to integrate FFmpeg into our program without having to call the executable to do an operation. This is important because starting up an external executable tends to be blocked by antivirus software and can cause issues with users. It has been tested for the most common functionality, and some of the examples from https://github.com/FFmpeg/FFmpeg/tree/master/doc/examples are mirrored in the project as well.

# Roadmap

- [ ] Solve all the warnings coming from libav

# License

[License](LICENSE.md)
