cmake_minimum_required(VERSION 3.10)
project(VoIPSignalingServer)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Add uWebSockets
add_subdirectory(libs/uWebSockets)

# Add your source files
file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp")

add_executable(voip_server ${SOURCES})

target_include_directories(voip_server PRIVATE 
    include
    libs/uWebSockets/src
    libs/uWebSockets/uSockets/src
)

target_link_libraries(voip_server PRIVATE uWebSockets)

# Find and link OpenSSL and ZLIB
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
target_link_libraries(voip_server PRIVATE OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB)

# Link pthread on Unix systems (except Apple)
if(UNIX AND NOT APPLE)
    target_link_libraries(voip_server PRIVATE pthread)
endif()