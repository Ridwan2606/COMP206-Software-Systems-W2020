#!/bin/bash

echo "This code will likely hang due to system configuration obstructing the use of shell memory for concurrent processes."
echo "Read comments inside code."
gcc -o shellmem shellmem.c
./shellmem
rm shellmem
exit