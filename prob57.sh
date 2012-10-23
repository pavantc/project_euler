#!/bin/bash

bc << EOF
define get_num_digits(num) {
	c=0;
	while (num) {
		c=c+1;
		num=num/10;
	}
	return c;
}

pn = 1;
pd = 1;
count=0;

for (i=0; i<1000; i++) {
	cd = pn+pd;
	cn = cd+pd;
	pn=cn;
	pd=cd;
	a = get_num_digits(cn);
	b = get_num_digits(cd);

	if (a > b) {
		count=count+1;
	}
}
pn
pd
count
EOF
