#!/usr/bin/env python3

import sys

def shrink(string):
	return string[:8]

def enlarge(string):
	while len(string) != 8:
		string += "Z"
	return string

args = sys.argv[1:]

if len(args) < 1:
	print("none")
else:
	i = 0
	for i in range(len(args)):
		if len(args[i]) > 8:
			args[i] = shrink(args[i])
		elif len(args[i]) < 8:
			args[i] = enlarge(args[i])
		print(args[i])
	

# Sequence[start:stop:step]
# [:3] i primi tre caratteri
# [-3:] gli ultimi tre
# [::2] ogni secondo carattere