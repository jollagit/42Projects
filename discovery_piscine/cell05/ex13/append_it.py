#!/usr/bin/env python3

import sys

match = "ism"
args = sys.argv[1:]

if len(args) < 1:
	print("none")
else:
	for i in range(len(args)):
		if not args[i].endswith(match):
			args[i] += match
		print(args[i])
	