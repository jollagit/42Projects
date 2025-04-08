#!/usr/bin/env python3

import sys

if len(sys.argv[1:]) != 1:
	print("none")
else:
	upper = sys.argv[1]
	print(upper.upper())
