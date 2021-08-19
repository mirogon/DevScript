cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(DevScript LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#list(APPEND _sourcefiles src/main.cpp src/DevScriptInterpreter.cpp src/ScriptParser/IScriptParser.cpp src/ScriptParser/ScriptParser.cpp)
file(GLOB_RECURSE _sourcefiles src/*.cpp)
add_executable(DevScript ${_sourcefiles}) 