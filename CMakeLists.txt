# Lots of hacky stuff here, just trying to learn how this all works !

cmake_minimum_required(VERSION 3.9.0)

project(shotoswm C)

set (WAYLAND_SCANNER wayland-scanner)
set (WAYLAND_PROTOCOLS /usr/share/wayland-protocols)
set (WAYLAND_PROTOCOL_DEF ${WAYLAND_PROTOCOLS}/stable/xdg-shell/xdg-shell.xml)

add_subdirectory(src)
