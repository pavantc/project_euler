#!/bin/bash

cat prob29.bc | bc -l | tr '\n' ':' | sed 's/\\://g' | tr ':' '\n' | sort -n | uniq | wc -l
