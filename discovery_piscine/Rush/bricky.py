#!/usr/bin/env python3

import os
import time
import pygame
import sys
import json

HIGHSCORE_FILE = "highscore.json"

def load_highscore():
	if os.path.exists(HIGHSCORE_FILE):
		with open(HIGHSCORE_FILE, "r") as f:
			data = json.load(f)
			return data.get("highscore", 0)
	return 0

def save_highscore(score):
	with open(HIGHSCORE_FILE, "w") as f:
		json.dump({"highscore": score}, f)

highscore = load_highscore()

def wait_seconds(seconds):
	time.sleep(seconds)

os.environ['SDL_VIDEO_WINDOW_POS'] = "0,0"

pygame.init()

width = 800
height = 600
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Breakout")

white = (255, 255, 255)
red = (255, 0, 0)
grey = (128, 128, 128)
blue = (0, 0, 255)
green = (0, 255, 0)
yellow = (255, 0, 255)

# piattaforma
width_plat = 100
height_plat = 15
x_plat = (width - width_plat) // 2
y_plat = height - height_plat - 10
speed_plat = 10

# pallina
size = 10
x = x_plat + (width_plat // 2)
y = y_plat - size
speed_x = 0
speed_y = 0
factor = 0.1

# pallina 2
size_2 = 10
x_2 = width // 2
y_2 = height // 2
speed_x_2 = 20
speed_y_2 = -20
double = False

# mattoncini
block_width= 60
block_height = 20
blocks = []

score = 0

lifes = 3
game_started = False

for i in range(4):
	for j in range(10):
		block = pygame.Rect(j * (block_width + 10) + 40, i * (block_height + 10) + 80, block_width, block_height)
		blocks.append(block)

pygame.display.flip()

# Font per il punteggio
font = pygame.font.SysFont("Terminal", 35)
heart_font = pygame.font.SysFont("DejaVu Sans", 40)
end_font = pygame.font.SysFont("Arial", 100)

clock = pygame.time.Clock()

while True:
	window.fill(grey)

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			sys.exit()

	# movimento della pallina
	x += speed_x * factor
	y += speed_y * factor

	# movimento pallina 2
	if double == True:
		x_2 += speed_x_2 * factor
		y_2 += speed_y_2 * factor

	# rimbalzi bordi laterali / bordo superiore
	if x - size <= 0 or x + size >= width:
		speed_x *= -1
	if y - size <= 0:
		speed_y *= -1

	# rimbalzi bordi laterali / bordo superiore pallina 2
	if double == True:
		if x_2 - size_2 <= 0 or x_2 + size_2 >= width:
			speed_x_2 *= -1
		if y_2 - size_2 <= 0:
			speed_y_2 *= -1

	# controllo movimenti piattaforma
	keys = pygame.key.get_pressed()
	if keys[pygame.K_LEFT] and x_plat > 0:
		if game_started == False:
			x_plat -= speed_plat
			x = x_plat + (width_plat // 2)
		else:
			x_plat -= speed_plat
	if keys[pygame.K_RIGHT] and x_plat < width - width_plat:
		if game_started == False:
			x_plat += speed_plat
			x = x_plat + (width_plat // 2)
		else:
			x_plat += speed_plat
	
	# condizione di vincita
	if not blocks:
		window.fill(grey)

		save_highscore(score)

		end_text = font.render("YOU WIN!", True, green)
		end_rect = end_text.get_rect(center = (width // 2, 300))
		window.blit(end_text, end_rect)

		score_text = font.render(f"{score}", True, white)
		score_rect = score_text.get_rect(center=(width // 2, 330))
		window.blit(score_text, score_rect)

		pygame.display.flip()
		wait_seconds(10)
		pygame.quit()
		sys.exit()

	# condizione di fine gioco
	if y > height:
		lifes -= 1
		if lifes == 0:
			window.fill(grey)

			save_highscore(score)

			end_text = font.render("GAME OVER!", True, red)
			end_rect = end_text.get_rect(center = (width // 2, 300))
			window.blit(end_text, end_rect)

			score_text = font.render(f"{score}", True, white)
			score_rect = score_text.get_rect(center=(width // 2, 330))
			window.blit(score_text, score_rect)

			pygame.display.flip()
			wait_seconds(10)
			pygame.quit()
			sys.exit()
		else:
			game_started = False
			x = x_plat + (width_plat // 2)
			y = y_plat - size
			speed_x = 0
			speed_y = 0

	# condizione di fine gioco pallina 2
	if double == True and y_2 > height:
			lifes -= 1
			double = False
			score += 10
			if lifes == 0:
				window.fill(grey)

				save_highscore(score)

				end_text = font.render("GAME OVER!", True, red)
				end_rect = end_text.get_rect(center = (width // 2, 300))
				window.blit(end_text, end_rect)

				score_text = font.render(f"{score}", True, white)
				score_rect = score_text.get_rect(center=(width // 2, 330))
				window.blit(score_text, score_rect)

				pygame.display.flip()
				wait_seconds(10)
				pygame.quit()
				sys.exit()

	# rimbalzo sulla piattaforma
	if (y + size >= y_plat and
		x > x_plat and
		x < x_plat + width_plat):
		speed_y *= -1
		y = y_plat - size

	# rimbalzo sulla piattaforma pallina 2
	if double == True:
		if (y_2 + size >= y_plat and
			x_2 > x_plat and
			x_2 < x_plat + width_plat):
			speed_y_2 *= -1
			y_2 = y_plat - size_2
	
	# gestione collisione con mattoni
	for block in blocks[:]:
		if block.collidepoint(x, y):
			blocks.remove(block)
			speed_y *= -1
			score += 10
			if score == 100:
				double = True
			elif score > highscore:
				highscore = score
			break

	# gestione collisione con mattoni pallina 2
	if double == True:
		for block in blocks[:]:
			if block.collidepoint(x_2, y_2):
				blocks.remove(block)
				speed_y_2 *= -1
				score += 10
				if score == 100:
					double = True
				elif score > highscore:
					highscore = score
				break

	# colorazione dei mattoni
	for i, block in enumerate(blocks):
		row = (block.top - 80) // (block_height + 10)
		if row == 0:
			color = blue
		elif row == 1:
			color = red
		elif row == 2:
			color = yellow
		else:
			color = green
		pygame.draw.rect(window, color, block)

	pygame.draw.circle(window, white, (x , y), size)
	if double == True:
		pygame.draw.circle(window, blue, (x_2 , y_2), size)

	pygame.draw.rect(window, white, (x_plat, y_plat, width_plat, height_plat))

	# Mostra il punteggio in alto al centro
	score_text = font.render(f"SCORE: {score}", True, white)
	score_rect = score_text.get_rect(center=(width // 2, 30))
	window.blit(score_text, score_rect)

	# Mostra l'high score in alto a destra
	highscore_text = font.render(f"HIGH: {highscore}", True, white)
	highscore_rect = highscore_text.get_rect(topright=(width - 10, 10))
	window.blit(highscore_text, highscore_rect)

	# Mostra cuori vite
	for i in range(lifes):
		heart_text = heart_font.render("❤️", True, (255, 0, 0))
		window.blit(heart_text, (10 + i * 30, 10))


	pygame.display.flip()

	keys = pygame.key.get_pressed()
	if game_started == False and keys[pygame.K_UP]:
		speed_x = 20
		speed_y = -20
		game_started = True
	
	clock.tick(100)
