#!/usr/bin/env python3

number = int(input("Enter a number less then 25\n"))

if number > 25:
	print("Error")
else:
	while number <= 25:
		print("Inside the loop, my variable is", number)
		number += 1