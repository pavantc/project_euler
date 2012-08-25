cat prob26.bc | bc -l | tr '\n' ':' | sed 's/\\://g' | tr ':' '\n' | sed 's/^[0-9]*\.//g'> prob26.input
./prob26
