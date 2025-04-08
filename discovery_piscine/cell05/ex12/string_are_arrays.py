#!/usr/bin/env python3

import sys

key = "z"
args = len(sys.argv[1:])

if args != 1 or key not in sys.argv[1]:
	print("none")
else:
	for c in sys.argv[1]:
		if c == key:
			print("z", end="")