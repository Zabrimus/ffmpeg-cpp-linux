executable('decode_audio',
           'decode_audio/decode_audio.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('decode_video',
           'decode_video/decode_video.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('demo',
           ['demo/demo.cpp', 'demo/GeneratedAudioSource.cpp', 'demo/GeneratedVideoSource.cpp'],
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('difference',
           'difference/difference.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('encode_audio',
           'encode_audio/encode_audio.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('encode_video',
           'encode_video/encode_video.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('filtering_video',
           'filtering_video/filtering_video.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('filtering_audio',
           'filtering_audio/filtering_audio.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('print_info',
           'print_info/print_info.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

executable('remuxing',
           'remuxing/remuxing.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

message('Source: ' + meson.project_source_root() + '/examples/samples')
message('Dest:   ' + meson.current_build_dir() + '/test')

run_command('cp', '-a', meson.project_source_root() + '/examples/samples', meson.current_build_dir(), check: true)
