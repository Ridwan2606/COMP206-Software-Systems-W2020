#!/bin/bash

echo "This code will likely hang due to system configuration obstructing the use of shell memory for concurrent processes."
echo "Read comments inside code."
gcc -o consumer consumer.c
gcc -o producer producer.c
export TURN=Producer
./producer & ./consumer
rm producer consumer
exit