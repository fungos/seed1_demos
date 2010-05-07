#!/bin/bash

echo Building SDL demo files
rm cache.sdl.txt 2> /dev/null
rm StringCache.txt 2> /dev/null
./sexporter -i sdl.xml -p sdl -v
cp sdl.h ../common/sdl/assets.h
