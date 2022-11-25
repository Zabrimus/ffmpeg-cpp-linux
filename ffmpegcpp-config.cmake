get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/${CMAKE_BUILD_TYPE}/ffmpegcpp.cmake)

get_filename_component(FFMPEGCPP_CONFIG_PATH "${CMAKE_CURRENT_LIST_DIR}" REALPATH)

find_package(PkgConfig)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET 
                    libavcodec
                    libavformat
                    libavutil
                    libavdevice
                    libavfilter )

set(FFMPEGCPP_INCLUDE_DIRS  "${FFMPEGCPP_CONFIG_PATH}/../../include/ffmpegcpp")
set(FFMPEGCPP_LIBS ffmpegcpp PkgConfig::LIBAV)

message(STATUS "-- Found FFMPEGCPP: version ${FFMPEGCPP_VERSION}")
