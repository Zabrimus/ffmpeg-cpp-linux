cmake_minimum_required(VERSION 3.11)

project(decode_audio)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} ffmpegcpp)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)