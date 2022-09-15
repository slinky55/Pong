cmake_minimum_required(VERSION 3.0)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/include include)
link_directories(/usr/local/lib)

#add_subdirectory(3rdparty/sfml)

file (GLOB_RECURSE SRCS src/*.cpp)

add_executable(Pong ${SRCS})

target_link_libraries(Pong PRIVATE
        sfml-system sfml-window sfml-graphics sfml-network)
