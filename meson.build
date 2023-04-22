project('ffmpeg-cpp-linux', 'cpp', 'c',
  version : '0.1',
  default_options : ['warning_level=1'],
  meson_version: '>=0.63.0')

add_global_arguments(language : 'cpp')

CXX = meson.get_compiler('cpp')
shared_libs = ['avcodec', 'avdevice', 'avfilter', 'avformat', 'avresample', 'avutil', 'postproc', 'swresample', 'swscale']
deps = []
foreach lib_name : shared_libs
        deps += CXX.find_library(lib_name)
endforeach

subdir('src')
inc = include_directories(['include'])


ffmpeg_cpp_lib = static_library(
  'ffmpeg_cpp',
  src,
  include_directories: inc,
  # dependencies: ffmpeg_cpp_dependencies,
  # cpp_args: ffmpeg_cpp_compile_args,
  # c_args: ffmpeg_cpp_compile_args,
)

ffmpeg_cpp_dep = declare_dependency(
    # dependencies: ffmpeg_cpp_dependencies,
    include_directories: inc,
    link_with: ffmpeg_cpp_lib,
    # compile_args: ffmpeg_cpp_compile_args,
)