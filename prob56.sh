#!/bin/bash

bc << EOF
define digsum(n) {
	s = 0
	while (n >= 1) {
		s = s + n%10;
		n = n/10;
	}
	return s
}

for (i=1; i<100; i++) {
	for (j=1; j<100; j++) {
		n=i^j
		s=digsum(n)
		if (max < s) {
			max = s
		}
	}
}

max
quit
EOF
