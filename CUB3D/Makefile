NAME		:= cub3d
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -I./include
RM			:= rm -rf
SRC_DIR		:= src
BUILD_DIR	:= .build
DIR_MKD		:= mkdir -p
INCLUDES 	:= -I/usr/include -Imlx_linux
MLX_FLAGS	:= -L./mlx_linux -lmlx -lXext -lX11 -lm

SRCS	:=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/keys.c \
				$(SRC_DIR)/rays.c \
				$(SRC_DIR)/draw.c \
				$(SRC_DIR)/texture.c \
				$(SRC_DIR)/movements.c

OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all	: header $(NAME)

$(NAME): $(OBJS)
			$(CC) $^ -o $@ $(MLX_FLAGS) && echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			$(DIR_MKD) $(@D)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
		$(RM) $(BUILD_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all


header: 
	${info }
	${info ${BOLD}Creating  ->${YELLOW}$(NAME)${NO_COLOR}}
	@if $(MAKE) -q $(NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME)${NO_COLOR}"; \
	fi

.PHONY: all re clean fclean header
.SILENT:

YELLOW		:= ${shell tput setaf 3}
GREEN		:= ${shell tput setaf 2}
RED			:= ${shell tput setaf 1}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}

