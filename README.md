# Pong-Cpp
A pong clone written in C++ using SFML

## About

This originaly was a project to learn networking, however I've decided to add more features to it and make a better game.

Current features:
- Main menu (with an AI game in the background)
- Singleplayer and Multiplayer modes
- Singleplayer opponent AI

Planned features:
- Currently connecting to the server requires typing into the console, I want this to be GUI based
- Player will be able choose whether to host a server on their own machine, or join another player's server
- AI will hopefully become more realistic and have diffuculty levels

## Building

**This has not been tested or built for Windows. I will be working on a simple way to build with Windows, this will probably be with an SFML submodule. If anyone can find a way to work nice with Windows, please submit a PR.**

First be sure to have SFML libraries installed on your system

For linux (Ubuntu/Debian): ```sudo apt install libsfml-dev```
For MacOS (Homebrew): ```brew install sfml```

Then clone the project: ```git clone --recurse-submodules git@github.com:slinky55/Pong-Cpp.git```

### Client
1. Build
```
cd PongClient &&
mkdir build-debug &&
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```
3. Run!
```
./build-debug/Pong
```

### Server
1. Build
```
cd PongServer-Cpp &&
mkdir build-debug &&
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```
3. Run!
```
cd build-debug && ./PongServer
```
