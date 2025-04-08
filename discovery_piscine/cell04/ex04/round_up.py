#!/usr/bin/env python3

import math

input = input("Give me a number: ")
number = float(input)
if number.is_integer():
	number = int(number)
print(math.ceil(number))