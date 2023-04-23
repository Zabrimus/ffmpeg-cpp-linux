executable('duration',
           'duration/duration.cpp',
           include_directories : inc,
           link_with : ffmpeg_cpp_lib)

run_command('cp', '-a', meson.project_source_root() + '/examples/samples', meson.current_build_dir(), check: true)
