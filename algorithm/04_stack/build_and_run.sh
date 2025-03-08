#!/bin/bash
if [ ! -d "output" ];then
	mkdir output
fi
gcc *.c -o output/s_stack
