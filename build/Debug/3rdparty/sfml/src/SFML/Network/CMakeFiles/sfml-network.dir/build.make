# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shaft/CLionProjects/Pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shaft/CLionProjects/Pong/build/Debug

# Include any dependencies generated for this target.
include 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.make

# Include the progress variables for this target.
include 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/progress.make

# Include the compile flags for this target's objects.
include 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: ../../3rdparty/sfml/src/SFML/Network/Ftp.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o -MF CMakeFiles/sfml-network.dir/Ftp.cpp.o.d -o CMakeFiles/sfml-network.dir/Ftp.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Ftp.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Ftp.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Ftp.cpp > CMakeFiles/sfml-network.dir/Ftp.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Ftp.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Ftp.cpp -o CMakeFiles/sfml-network.dir/Ftp.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: ../../3rdparty/sfml/src/SFML/Network/Http.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o -MF CMakeFiles/sfml-network.dir/Http.cpp.o.d -o CMakeFiles/sfml-network.dir/Http.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Http.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Http.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Http.cpp > CMakeFiles/sfml-network.dir/Http.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Http.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Http.cpp -o CMakeFiles/sfml-network.dir/Http.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: ../../3rdparty/sfml/src/SFML/Network/IpAddress.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o -MF CMakeFiles/sfml-network.dir/IpAddress.cpp.o.d -o CMakeFiles/sfml-network.dir/IpAddress.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/IpAddress.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/IpAddress.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/IpAddress.cpp > CMakeFiles/sfml-network.dir/IpAddress.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/IpAddress.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/IpAddress.cpp -o CMakeFiles/sfml-network.dir/IpAddress.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: ../../3rdparty/sfml/src/SFML/Network/Packet.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o -MF CMakeFiles/sfml-network.dir/Packet.cpp.o.d -o CMakeFiles/sfml-network.dir/Packet.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Packet.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Packet.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Packet.cpp > CMakeFiles/sfml-network.dir/Packet.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Packet.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Packet.cpp -o CMakeFiles/sfml-network.dir/Packet.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: ../../3rdparty/sfml/src/SFML/Network/Socket.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o -MF CMakeFiles/sfml-network.dir/Socket.cpp.o.d -o CMakeFiles/sfml-network.dir/Socket.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Socket.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Socket.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Socket.cpp > CMakeFiles/sfml-network.dir/Socket.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Socket.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Socket.cpp -o CMakeFiles/sfml-network.dir/Socket.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: ../../3rdparty/sfml/src/SFML/Network/SocketSelector.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o -MF CMakeFiles/sfml-network.dir/SocketSelector.cpp.o.d -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/SocketSelector.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/SocketSelector.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/SocketSelector.cpp > CMakeFiles/sfml-network.dir/SocketSelector.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/SocketSelector.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/SocketSelector.cpp -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: ../../3rdparty/sfml/src/SFML/Network/TcpListener.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o -MF CMakeFiles/sfml-network.dir/TcpListener.cpp.o.d -o CMakeFiles/sfml-network.dir/TcpListener.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/TcpListener.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpListener.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/TcpListener.cpp > CMakeFiles/sfml-network.dir/TcpListener.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpListener.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/TcpListener.cpp -o CMakeFiles/sfml-network.dir/TcpListener.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: ../../3rdparty/sfml/src/SFML/Network/TcpSocket.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o -MF CMakeFiles/sfml-network.dir/TcpSocket.cpp.o.d -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/TcpSocket.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpSocket.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/TcpSocket.cpp > CMakeFiles/sfml-network.dir/TcpSocket.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpSocket.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/TcpSocket.cpp -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: ../../3rdparty/sfml/src/SFML/Network/UdpSocket.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o -MF CMakeFiles/sfml-network.dir/UdpSocket.cpp.o.d -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/UdpSocket.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/UdpSocket.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/UdpSocket.cpp > CMakeFiles/sfml-network.dir/UdpSocket.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/UdpSocket.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/UdpSocket.cpp -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.s

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: ../../3rdparty/sfml/src/SFML/Network/Unix/SocketImpl.cpp
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o -MF CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o.d -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o -c /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Unix/SocketImpl.cpp

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Unix/SocketImpl.cpp > CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && /bin/x86_64-pc-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network/Unix/SocketImpl.cpp -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s

# Object files for target sfml-network
sfml__network_OBJECTS = \
"CMakeFiles/sfml-network.dir/Ftp.cpp.o" \
"CMakeFiles/sfml-network.dir/Http.cpp.o" \
"CMakeFiles/sfml-network.dir/IpAddress.cpp.o" \
"CMakeFiles/sfml-network.dir/Packet.cpp.o" \
"CMakeFiles/sfml-network.dir/Socket.cpp.o" \
"CMakeFiles/sfml-network.dir/SocketSelector.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpListener.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/UdpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"

# External object files for target sfml-network
sfml__network_EXTERNAL_OBJECTS =

3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/build.make
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/lib/libsfml-system-d.so.3.0.0
3rdparty/sfml/lib/libsfml-network-d.so.3.0.0: 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shaft/CLionProjects/Pong/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library ../../../lib/libsfml-network-d.so"
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml-network.dir/link.txt --verbose=$(VERBOSE)
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../lib/libsfml-network-d.so.3.0.0 ../../../lib/libsfml-network-d.so.3.0 ../../../lib/libsfml-network-d.so

3rdparty/sfml/lib/libsfml-network-d.so.3.0: 3rdparty/sfml/lib/libsfml-network-d.so.3.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate 3rdparty/sfml/lib/libsfml-network-d.so.3.0

3rdparty/sfml/lib/libsfml-network-d.so: 3rdparty/sfml/lib/libsfml-network-d.so.3.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate 3rdparty/sfml/lib/libsfml-network-d.so

# Rule to build all files generated by this target.
3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/build: 3rdparty/sfml/lib/libsfml-network-d.so
.PHONY : 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/build

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/clean:
	cd /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network && $(CMAKE_COMMAND) -P CMakeFiles/sfml-network.dir/cmake_clean.cmake
.PHONY : 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/clean

3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/depend:
	cd /home/shaft/CLionProjects/Pong/build/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shaft/CLionProjects/Pong /home/shaft/CLionProjects/Pong/3rdparty/sfml/src/SFML/Network /home/shaft/CLionProjects/Pong/build/Debug /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network /home/shaft/CLionProjects/Pong/build/Debug/3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3rdparty/sfml/src/SFML/Network/CMakeFiles/sfml-network.dir/depend

