get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/${CMAKE_BUILD_TYPE}/ffmpegcpp.cmake)

get_filename_component(FFMPEGCPP_CONFIG_PATH "${CMAKE_CURRENT_LIST_DIR}" REALPATH)

set(FFMPEGCPP_INCLUDE_DIRS  "${FFMPEGCPP_CONFIG_PATH}/../../include/ffmpegcpp")
set(FFMPEGCPP_LIBS ffmpegcpp)

message(-- " FFMPEGCPP found: version ${FFMPEGCPP_VERSION}")
