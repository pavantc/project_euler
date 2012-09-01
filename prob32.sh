#!/bin/bash

./prob32 | awk '{print $NF}' | sort | uniq | sed 's/^/.+/' | bc -l | tail -1
