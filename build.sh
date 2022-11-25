#!/bin/bash

SCRIPTPATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
BUILD_DIR=$SCRIPTPATH/build
LIB_STATUS=ON
EX_STATUS=OFF
BUILD_EX=-DBUILD_EXAMPLES
BUILD_LIB=-DBUILD_SHARED_LIB

help()
{
    echo "Build the source code"
    echo
    echo "Syntax: $0 [-a|c|e|l|h|i]"
    echo "a     Build all"
    echo "c     Clean build directory"
    echo "e     Build examples"
    echo "l     Build library only"
    echo "h     Help"
    echo "i     Install library. (Default path: /usr/local/)"
    echo
    echo "Examples:"
    echo "$0 -a     Builds all"
}

build_all=n
build_examples=n
build_library=n
build=n
install_lib=n
clean=n

if [ $# -eq 0 ]; then
    echo "Error: missing argument"
    help
    exit 0
else
    while getopts ":acelhi" opt; do
        case $opt in
            a)
                build_all=y
                ;;
            c)
                clean=y
                ;;
            e)
                build_examples=y
                ;;
            l)
                build_library=y
                ;;
            h)
                help
                exit 1
                ;;
            i)
                install_lib=y
                ;;
            \?)
                help
                exit 1
                ;;
            :)
                echo "Option -$OPTARG requires an argument." >&2
                exit 1
                ;;
        esac
    done
fi

mkdir -p $BUILD_DIR

if [ $build_all == y ]; then
    echo "=== Building all ==="
    EX_STATUS=ON
    LIB_STATUS=ON
    build=y
fi

if [ $build_examples == y ]; then
    echo "=== Building examples only ==="
    EX_STATUS=ON
    build=y
fi

if [ $build_library == y ]; then
    echo "=== Building library only ==="
    build=y
fi

if [ $build == y ]; then
    cd $BUILD_DIR
    cmake $BUILD_LIB=$LIB_STATUS $BUILD_EX=$EX_STATUS ..
    make -j4
    if [ $? == 0 ]; then
        echo "=== Building done ==="
    else
        echo "=== Building failed ==="
        clean=y
    fi
    cd $SCRIPTPATH
fi

if [ $install_lib == y ]; then
    cd $BUILD_DIR
    sudo make install
fi

if [ $clean == y ]; then
    echo "=== Cleaning ==="
    sudo rm -rf $BUILD_DIR
fi