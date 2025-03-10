#!/bin/bash
if [ ! -d "output" ];then
	mkdir output
fi
gcc s_stack.c -o output/s_stack
gcc s_queue.c -o output/s_queue
echo "............start exec s_stack................"
./output/s_stack
echo "............start exec s_queue................"
./output/s_queue
