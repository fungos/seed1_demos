#!/bin/bash

for FN in `find . -name '*~'`
do
        rm -i $FN
done

for FN in `find . -name '*.o'`
do
        rm -i $FN -f
done
