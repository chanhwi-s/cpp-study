cmake_minimum_required(VERSION 3.16)

project(cpp_study)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SOURCE_FILE 변수를 외부에서 받음
if(NOT DEFINED SOURCE_FILE)
    message(FATAL_ERROR "SOURCE_FILE not specified")
endif()

add_executable(run ${SOURCE_FILE})
