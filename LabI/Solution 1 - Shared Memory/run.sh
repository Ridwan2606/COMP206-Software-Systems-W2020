#!/bin/bash

gcc -o sharedmem sharedmem.c
./sharedmem
rm sharedmem
exit