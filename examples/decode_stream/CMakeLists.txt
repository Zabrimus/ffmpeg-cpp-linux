cmake_minimum_required(VERSION 3.11)

project(decode_stream)

find_package(PkgConfig REQUIRED)
find_package(OpenCV REQUIRED)
pkg_check_modules(SWS REQUIRED IMPORTED_TARGET libswscale)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${FFMPEGCPP_INCLUDE_DIRS})

file(COPY stream_srv.sh DESTINATION ${CMAKE_BINARY_DIR}/apps)

file(GLOB SRC *.cpp)
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ffmpegcpp ${OpenCV_LIBS} PkgConfig::SWS)