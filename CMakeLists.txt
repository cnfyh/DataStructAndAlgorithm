cmake_minimum_required(VERSION 4.3.1)
project(datastructandalgorighthm)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB_RECURSE TEMP CONFIGURE_DEPENDS src/*.cpp)
add_executable(a ${TEMP})
target_include_directories(a PRIVATE include)

