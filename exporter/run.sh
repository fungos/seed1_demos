#!/bin/bash

echo Building SDL demo files
rm cache.sdl.txt 2> /dev/null
rm StringCache.txt 2> /dev/null
./sexporter -i seeddemos.xml -p sdl -v
cp seeddemos.h ../common/sdl/assets.h
