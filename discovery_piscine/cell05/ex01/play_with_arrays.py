#!/usr/bin/env python3

numbers = [2, 17, -4, 12, 34, -76]
array = [0] * len(numbers)

i = 0
for i in range(len(numbers)):
	array[i] = numbers[i] + 2
	i += 1

print("Original array: ", numbers)
print("New array: ", array)