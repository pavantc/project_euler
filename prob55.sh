#!/bin/bash

bc << EOF
define rev(s) {
	k = 0;
	while (s >= 1) {
		r = s%10;
		k = k*10 + r;
		s = s/10;
	}
	return k
}

count=0;

for (i=1; i<10001; i++) {
	s=i;
	for (j=0; j<50; j++) {
		s=s+rev(s);
		if (s==rev(s)) {
			break;
		}
	}
	if (j==50) {
		count=count+1;
	}
}
count
quit
EOF
