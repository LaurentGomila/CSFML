#!/bin/bash

# Automatically exit on error
set -e

dnf install -y \
    git \
    freetype-devel \
    xorg-x11-server-devel \
    libXrandr-devel \
    libXcursor-devel \
    libXi-devel \
    systemd-devel \
    mesa-libEGL-devel \
    flac-devel \
    libogg-devel \
    libvorbis-devel \
    gcc-c++ \
    cmake \
    make

./build.linux.sh fedora-x64
