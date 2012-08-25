#!/bin/bash

echo `seq 1 100` | sed 's/ /\*/g'| bc -l | sed 's/\\//' | tr '\n' ' ' | sed 's/ //g' | sed 's/[0-9]/&\n/g' | sed 's/^/.+/'| bc -l | tail -1
