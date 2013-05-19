#!/bin/bash

JOBS="-j3"

function build_targets()
{

    make $JOBS CPU_TARGET=i386 OS_TARGET=linux $@
    make $JOBS CPU_TARGET=x86_64 OS_TARGET=win64 $@
}

build_targets DEBUG=1
build_targets DEBUG=0
