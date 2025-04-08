#!/usr/bin/env python3

import sys

n_args = len(sys.argv[1:])

if n_args == 0:
	print("none")
else:
	print(n_args)
	for i in range(1, len(sys.argv)):
		print(f"{sys.argv[i]}: {len(sys.argv[i])}")
