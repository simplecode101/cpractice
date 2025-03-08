#!/bin/bash
if [ ! -d "output" ];then
	mkdir output
fi
gcc s_linkedlist.c -o output/s_linkedlist
