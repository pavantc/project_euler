#!/bin/bash

a="1"
b="1"
c=2
while :
do
	n="`echo $a + $b | bc -l | sed 's/\\\//g' | tr '\n' ' ' | sed 's/ //g'`"
	a="$b"
	b="$n"
	c=$((c+1))
	if [ `echo $b | wc -c` -gt 1000 ]
	then
		break
	fi
done
echo $b
echo $c
