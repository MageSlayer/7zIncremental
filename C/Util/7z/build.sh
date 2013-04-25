#!/bin/bash

# build script for gcc
GCC_FLAGS="-O0 -g -ggdb -g3"

make GCC_FLAGS="$GCC_FLAGS" -f makefile.gcc