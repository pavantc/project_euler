#!/bin/bash

#  sed -e 's/\\$//' - bc produces a '\' when the number of digits per line
#  crosses 80. Remove the '\'
#  sed -e 's/[0-9]/&\n/g' - Insert a newline after every number
#  grep -v ^$ - Remove all empty lines
#  Add a '.+' in front of every line so that the output can be piped to 'bc'

echo "2^1000" | bc -l| sed -e 's/\\$//' -e 's/[0-9]/&\n/g' | grep -v ^$ | sed 's/^/.+/' | bc -l | tail -1
