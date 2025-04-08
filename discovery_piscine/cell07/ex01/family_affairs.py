#!/usr/bin/env python3

def find_the_redheads(dupont_family):
	redhead = filter(lambda item: item[1] == "red", dupont_family.items())
	return list(map(lambda item: item[0], redhead))
	
dupont_family = {
"florian": "red",
"marie": "blond",
"virginie": "brunette",
"david": "red",
"franck": "red"
}

print(find_the_redheads(dupont_family))