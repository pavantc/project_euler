#!/bin/bash

a=`cat prob48.bc | bc -l | tr '\n' '\\\' | sed 's/\\\//g'`
b=`echo $a | wc -c`
echo $a | cut -b$((b-10))-
