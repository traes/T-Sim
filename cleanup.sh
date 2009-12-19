#!/bin/sh

# remove system-dependant CMake files
rm -rf -- CMakeCache.txt CMakeFiles cmake_install.cmake Makefile

# remove documentation
rm -rf -- doc

# remove binary
rm T-Sim

clear
