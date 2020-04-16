#!/bin/bash

gcc -o consumer consumer.c
gcc -o producer producer.c
./producer & ./consumer
rm producer consumer
exit