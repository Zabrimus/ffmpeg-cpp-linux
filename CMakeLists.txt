cmake_minimum_required(VERSION 3.11)

project(FFMPEG-CPP-LINUX)

set(LIB_NAME ffmpegcpp)

set(${PROJECT_NAME}_VERSION_MAJOR 1 CACHE STRING "major version" FORCE)
set(${PROJECT_NAME}_VERSION_MINOR 0 CACHE STRING "minor version" FORCE)
set(${PROJECT_NAME}_VERSION ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR} CACHE STRING "version" FORCE)

set(BASE_INSTALL_PATH "/usr/local")
set(include_dest "${BASE_INSTALL_PATH}/include/${LIB_NAME}")
set(main_lib_dest "${BASE_INSTALL_PATH}/lib/${LIB_NAME}")
set(lib_dest "${main_lib_dest}/${CMAKE_BUILD_TYPE}")
# Space for options

install(FILES ${LIB_NAME}-config.cmake DESTINATION ${main_lib_dest})
configure_file(${LIB_NAME}-config-version.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}-config-version.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}-config-version.cmake DESTINATION ${main_lib_dest})

find_package(PkgConfig)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET 
                    libavcodec
                    libavformat
                    libavutil
                    libavdevice
                    libavfilter )

option(BUILD_SHARED_LIB "Build ffmpeg as shared library" ON)
option(BUILD_EXAMPLES "Build some examples to show how the library works" OFF)

# Subdirectories
if (BUILD_SHARED_LIB)
    add_subdirectory(src)
endif()

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()