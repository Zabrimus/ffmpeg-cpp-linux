cmake_minimum_required(VERSION 3.11)

project(difference)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} ffmpegcpp)