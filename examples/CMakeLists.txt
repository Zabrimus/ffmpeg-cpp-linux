cmake_minimum_required(VERSION 3.11)

find_package(PkgConfig)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(COPY samples DESTINATION ${CMAKE_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR})
add_subdirectory(decode_audio)
add_subdirectory(demo)
add_subdirectory(decode_video)