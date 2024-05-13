NAME = libft.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_printf.c \
			ft_print_hex.c \
			ft_print_ptr.c \
			ft_print_nbr.c \
			ft_print_unbr.c \
			ft_print_str.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: header $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) && echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I../include

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

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