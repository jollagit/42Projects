#!/usr/bin/env python3

import sys
import re

args = sys.argv[1:]

if len(args) != 2 or args[0] not in args[1]:
	print("none")
else:
	key = re.escape(args[0])
	string = args[1]
	print(len(re.findall(key, string)))
