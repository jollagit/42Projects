#!/usr/bin/env python3

numbers = [2, 4, 7, -14, 20, 1]

j = 0
i = len(numbers)

print("[", end="")
while j < i:
	if j == i -1:
		print(f"{numbers[j]}]")
		break
	else:
		print(numbers[j], end=", ")
	j += 1