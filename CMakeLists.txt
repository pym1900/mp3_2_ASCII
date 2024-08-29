cmake_minimum_required(VERSION 3.10)

# Project name
project(VideoToASCII)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add the executable
add_executable(VideoToASCII main.cpp)

# Link OpenCV libraries
target_link_libraries(VideoToASCII ${OpenCV_LIBS})
