#!/usr/bin/env python3

def average(classes):
	sum = 0
	len = 0
	for name, score in classes.items():
		sum += score
		len += 1
	return sum / len

class_3B = {
"marine": 18,
"jean": 15,
"coline": 8,
"luc": 9
}
class_3C = {
"quentin": 17,
"julie": 15,
"marc": 8,
"stephanie": 13
}

print(f"Average for class 3B: {average(class_3B)}.")
print(f"Average for class 3C: {average(class_3C)}.")