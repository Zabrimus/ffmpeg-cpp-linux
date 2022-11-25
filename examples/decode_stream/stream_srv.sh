#!/bin/bash

PORT=5000
HOST=127.0.0.1
FILE=big_buck_bunny.mp4

gst-launch-1.0 filesrc location = samples/${FILE} \
    ! qtdemux \
    ! h264parse \
    ! avdec_h264 \
    ! videoconvert \
    ! x264enc key-int-max=12 byte-stream=true \
    ! tcpserversink port=$PORT host=$HOST