# Lots of hacky stuff here, just trying to learn how this all works !

cmake_minimum_required(VERSION 3.9.0)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(TARGETNAME shotoswm)

# add_executable(${WAYLAND_SCANNER} xdg-shell-protocol.h)
add_custom_command(
    OUTPUT xdg-shell-protocol.h
    COMMAND ${WAYLAND_SCANNER}
        server-header ${WAYLAND_PROTOCOL_DEF} xdg-shell-protocol.h
    DEPENDS ${WAYLAND_PROTOCOL_DEF}
    COMMENT "Genearting protocol headers...")

add_custom_command(
    OUTPUT xdg-shell-protocol.c
    COMMAND ${WAYLAND_SCANNER}
        private-code ${WAYLAND_PROTOCOL_DEF} xdg-shell-protocol.c
    DEPENDS ${WAYLAND_PROTOCOL_DEF} xdg-shell-protocol.h
    COMMENT "Genearting protocol source...")

file(GLOB SOURCES *.c *.cpp)
add_executable(
    ${TARGETNAME} 
    ${SOURCES}
    xdg-shell-protocol.c)

target_compile_options(${TARGETNAME} PRIVATE -DWLR_USE_UNSTABLE)

target_link_libraries(${TARGETNAME}
    wlroots
    wayland-server
    xkbcommon)

include_directories(
    /usr/include
    /usr/include/pixman-1
    ${CMAKE_CURRENT_BINARY_DIR})
