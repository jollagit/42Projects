#!/usr/bin/env python3

numbers = [2, 8, 9, 48, 8, 22, -12, 2]
array = []

for i in range(len(numbers)):
	if numbers[i] > 5:
		array.append(numbers[i] + 2)
print(numbers)
print(set(array))