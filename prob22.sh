#!/bin/bash

s=0
c=0

for i in `cat n.txt`
do
	c=$((c+1))
	t=0
	for j in `echo $i| sed 's/[A-Z]/& /g'`
	do
		t=$((t + $((`printf "%d - 64" "'$j"`))));
	done
	s=$((s + t * c))
done

echo $s
