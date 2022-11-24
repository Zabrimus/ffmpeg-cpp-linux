cmake_minimum_required(VERSION 3.11)

project(demo)

file(GLOB SRC *.cpp)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ffmpegcpp)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)