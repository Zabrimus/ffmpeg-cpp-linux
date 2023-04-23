project('ffmpeg-cpp-linux', 'cpp', 'c',
  version : '0.1',
  default_options : ['warning_level=1'],
  meson_version: '>=0.63.0')

add_global_arguments(language : 'cpp')

avcodev_dep = dependency('libavcodec', required: true)
avdevice_dep = dependency('libavdevice', required: true)
avfilter_dep = dependency('libavfilter', required: true)
avformat_dep = dependency('libavformat', required: true)
avresample_dep = dependency('libavresample', required: true)
avutil_dep = dependency('libavutil', required: true)
postproc_dep = dependency('libpostproc', required: true)
swresample_dep = dependency('libswresample', required: true)
swscale_dep = dependency('libswscale', required: true)

ffmpeg_cpp_dep = [avcodev_dep, avdevice_dep, avfilter_dep, avformat_dep, avutil_dep, postproc_dep, swresample_dep, swscale_dep]

subdir('src')
inc = include_directories(['include'])

ffmpeg_cpp_lib = static_library(
  'ffmpeg_cpp',
  src,
  include_directories: inc,
  dependencies: ffmpeg_cpp_dep,
)

subdir('examples')