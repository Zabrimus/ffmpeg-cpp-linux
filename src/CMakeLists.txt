# set headers
set(LIB_SOURCE_DIR ${${PROJECT_NAME}_SOURCE_DIR})
set(header_path ${LIB_SOURCE_DIR}/include/ffmpegcpp)

file(GLOB_RECURSE HEADER ${header_path}/*.h ${header_path}/*.hpp)
file(GLOB SRC *.cpp)

configure_file("config.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp")

add_library(${LIB_NAME} SHARED ${HEADER} ${SRC})
target_link_libraries(${LIB_NAME} PkgConfig::LIBAV)
target_include_directories(${LIB_NAME} PUBLIC   $<BUILD_INTERFACE:${LIB_SOURCE_DIR}/include> 
                                                $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
                                                $<INSTALL_INTERFACE:${include_dest}>
                                                $<INSTALL_INTERFACE:${lib_dest}>)

install(TARGETS ${LIB_NAME} DESTINATION ${main_lib_dest})
install(DIRECTORY ${header_path}/ DESTINATION ${include_dest})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${include_dest}")
install(TARGETS ${LIB_NAME} EXPORT ${LIB_NAME} DESTINATION "${lib_dest}")
install(EXPORT ${LIB_NAME} DESTINATION "${lib_dest}")