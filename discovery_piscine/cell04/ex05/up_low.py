#!/usr/bin/env python3

input = input()
result = ""
for char in input:
	if char.isupper():
		result += char.lower()
	elif char.islower():
		result += char.upper()
	else:
		result += char
print(result)

# le stringhe su python sono immutabili
# quindi e' importante salvare il risultato delle funzioni .upper() .lower()
# che non modificano char direttamente