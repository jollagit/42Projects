#!/usr/bin/env python3

number = int(input("Enter a number\n"))
count = 0

while count < 10:
	print(f"{count} x {number} = {count * number}")
	count += 1