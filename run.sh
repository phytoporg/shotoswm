#!/usr/bin/sh

kwin_wayland --xwayland --socket wayland-1 --width 640 --height 480 &
sleep 2
WAYLAND_DISPLAY=wayland-1 ./build/shotoswm -s alacritty
