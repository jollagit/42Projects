#!/usr/bin/env python3

age = int(input("Please tell me your age: "))

print("You are currently", age, "years old.")

i = 10
while i <= 30:
	print("In", i, "years, you'll be", i + age, "years old.")
	i += 10