cmake_minimum_required(VERSION 3.10)
project(VoIPSignalingServer)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Add uWebSockets
add_subdirectory(third_party/uWebSockets)

# Add your source files
file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp")

add_executable(voip_server ${SOURCES})

target_include_directories(voip_server PRIVATE include)
target_link_libraries(voip_server PRIVATE uWebSockets)