#!/usr/bin/env python3

def array_of_names(names_dict):
	array = []
	for first_name, last_name in names_dict.items():
		array.append(f"{first_name} {last_name}")
	return array

names_dict = {
"jean": "valjean",
"grace": "hopper",
"xavier": "niel",
"fifi": "brindacier"
}

print(array_of_names(names_dict))