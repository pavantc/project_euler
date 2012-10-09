#!/bin/bash

bc -l << EOF
define f(x) {
  if (x > 1) {
     return (x * f(x-1))
  }
  return (1)
}

for(n=1; n<=100; n++) {
  for (r=1; r<=n; r++) {
    ncr=f(n)/(f(n-r) * f(r))
    if (ncr >= 1000000) {
      c = c+1
    }
  }
}
c
quit
EOF
