#!/usr/bin/env python3

numbers = [2, 8, 9, 22, -12]
array = []

for i in range(len(numbers)):
	if numbers[i] > 5:
		array.append(numbers[i] + 2)
print(array)

# oppure array = [x + 2 for x in numbers if x > 5]