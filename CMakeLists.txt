cmake_minimum_required(VERSION 2.8)
project(string)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( string string.cpp )
target_link_libraries( string ${OpenCV_LIBS} )

