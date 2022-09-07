cmake_minimum_required(VERSION 3.23)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(3rdparty/sfml)

add_executable(Pong main.cpp)

target_link_libraries(Pong PRIVATE
        sfml-system sfml-window sfml-graphics)
