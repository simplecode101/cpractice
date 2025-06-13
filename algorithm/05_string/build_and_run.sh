#!/bin/bash
if [ ! -d "output" ];then
	mkdir output
fi
gcc s_string.c -o output/s_string
echo "............start exec s_string................"
./output/s_string
