#!/usr/bin/env python3

import os

professor = input("Nome utente: ").strip()
with open("professore.txt", "w") as file:
	file.write(professor)
if os.path.exists("professore.txt"):
	with open("professore.txt", "r") as file:
		professor = file.read().strip()

activity = []

while True:
	subject = input("Inserire la materia dell'attivita': ").strip()
	if subject.upper() == "CLOSE":
		break
	day = input("Inserire il giorno dell'attivita': ").strip()
	if subject.upper() == "CLOSE":
		break
	subject_type = input("Inserire la tipologia dell'attivita': ").strip()
	if subject.upper() == "CLOSE":
		break
	hours = input("Inserire l'orario dell'attivita: ").strip()
	if subject.upper() == "CLOSE":
		break
	duration = input("Inserire la durata dell'attivita': ").strip()
	if subject.upper() == "CLOSE":
		break

# controlla salvataggio dell'input in caso di input non corretto e troncatura del ciclo while

	activity.append({
		"materia": subject,
		"giorno": day,
		"lezione": subject_type,
		"ore": hours,
		"durata": duration
	})

	print("\nAttivita' creata!\n")

with open("activita'.txt", "w") as file:
	for i in activity:
		file.write(f"{i['materia']} | {i['giorno']} | {i['lezione']} | {i['ore']} | {i['durata']}")

print("Attivita' salvate nel file 'attivita'.txt")

Hours = {}
lection_hours = 0
interrogation_hours = 0

for i in activity:
	materia = i["materia"]
	giorno = i["giorno"]
	lezione = i["lezione"]
	ore = i["ore"]
	durata = i["durata"]

	if giorno not in Hours:
		Hours[giorno] = []
	Hours[giorno].append(f"- {lezione} - {materia} ({ore})")

	if lezione.lower() == "lezione":
		lection_hours += int(durata)
	elif lezione.lower() == "interrogazione":
		interrogation_hours += int(durata)

file_name = f"orario_{professor.replace(' ', '_')}.txt"
header = f"===== Orario Lezioni di {professor.replace(' ', ' ')} ====="
print(header)
with open(file_name, "w") as file:
	file.write(header)

	for giorno in sorted(Hours.keys()):
		print((f"{giorno} :"))
		file.write(f"{giorno} :\n")
		for item in Hours[giorno]:
			print(item)
			file.write(item + "\n")

	summary = f"\nTotale ore di lezione: {lection_hours} ore\nTotale ore di interrogazione: {interrogation_hours} ore\n"
	print(summary)
	file.write(summary)

print(f"Orario salvato nel file \"{file_name}\"")