NAME = libft.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS := ${wildcard *.c} 

OBJS = $(SRCS:.c=.o)

all: header $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) && echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I../include

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

header:
		${info }
		${info ${BOLD}Creating  ->${YELLOW}$(NAME)${NO_COLOR}}
		@if $(MAKE) -q $(NAME) ; then \
				echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME)${NO_COLOR}"; \
				fi

.PHONY: all clean fclean re bonus
.SILENT:

YELLOW			:= ${shell tput setaf 3}
GREEN			:= ${shell tput setaf 2}
RED				:= ${shell tput setaf 1}
NO_COLOR		:= ${shell tput sgr0}
BOLD			:= ${shell tput bold}