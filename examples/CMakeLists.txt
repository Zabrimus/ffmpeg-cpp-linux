cmake_minimum_required(VERSION 3.11)

find_package(PkgConfig)

include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_SOURCE_DIR}/../../build/src/lib)

file(COPY samples DESTINATION ${CMAKE_BINARY_DIR}/apps)

set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/apps)

add_subdirectory(decode_audio)
if(${BUILD_DECODE_STREAM})
    add_subdirectory(decode_stream)
endif()
add_subdirectory(decode_video)
add_subdirectory(demo)
add_subdirectory(difference)
add_subdirectory(encode_audio)
add_subdirectory(encode_video)
add_subdirectory(filtering_audio)
add_subdirectory(filtering_video)
add_subdirectory(print_info)
add_subdirectory(remuxing)