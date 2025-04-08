#!/usr/bin/env python3

import sys

array = []

if len(sys.argv[1:]) != 2:
	print("none")
else:
	print("[", end="")
	for i in range(int(sys.argv[1]), int(sys.argv[2]) + 1):
		array.append(i)
		if i != int(sys.argv[2]):
			print(i, end=", ")
		else:
			print(f"{i}]")


# oppure else: start = int(sys.argv[1]) / end = int(sys.argv[2])
# array = list(range(start, end + 1)) / print(array)