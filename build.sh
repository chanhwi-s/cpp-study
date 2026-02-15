#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: ./build.sh <filename_without_extension>"
    exit 1
fi

FILE_NAME=$1
SOURCE_FILE=src/${FILE_NAME}.cpp
BUILD_DIR=build

if [ ! -f "$SOURCE_FILE" ]; then
    echo "File $SOURCE_FILE does. not exist."
    exit 1
fi

rm -rf $BUILD_DIR
mkdir $BUILD_DIR
cd $BUILD_DIR

cmake -DSOURCE_FILE=$SOURCE_FILE -DCMAKE_BUILD_TYPE=Debug ..
make

if [ $? -ne 0 ]; then
    echo "Build failed."
    exit 1
fi

./run
