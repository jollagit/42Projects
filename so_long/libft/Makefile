NAME			:= libft.a
CC				:= cc 
CFLAGS			:= -Wall -Wextra -Werror -I../include

RM				:= rm -rf
AR				:= ar rcs
BUILD_DIR		:= .build

SRC_DIR 		:= src
SRC_DIR_BONUS	:= src_bonus
DIR_MKD			:= mkdir -p $(@D)

SRCS = $(SRC_DIR)/ft_isalpha.c \
			$(SRC_DIR)/ft_isdigit.c \
			$(SRC_DIR)/ft_isalnum.c \
			$(SRC_DIR)/ft_isascii.c \
			$(SRC_DIR)/ft_isprint.c \
			$(SRC_DIR)/ft_strlen.c \
			$(SRC_DIR)/ft_memset.c \
			$(SRC_DIR)/ft_bzero.c \
			$(SRC_DIR)/ft_memcpy.c \
			$(SRC_DIR)/ft_memmove.c \
			$(SRC_DIR)/ft_strlcpy.c \
			$(SRC_DIR)/ft_strlcat.c \
			$(SRC_DIR)/ft_toupper.c \
			$(SRC_DIR)/ft_tolower.c \
			$(SRC_DIR)/ft_strchr.c \
			$(SRC_DIR)/ft_strrchr.c \
			$(SRC_DIR)/ft_strncmp.c \
			$(SRC_DIR)/ft_memchr.c \
			$(SRC_DIR)/ft_memcmp.c \
			$(SRC_DIR)/ft_strnstr.c \
			$(SRC_DIR)/ft_atoi.c \
			$(SRC_DIR)/ft_calloc.c \
			$(SRC_DIR)/ft_strdup.c \
			$(SRC_DIR)/ft_substr.c \
			$(SRC_DIR)/ft_strjoin.c \
			$(SRC_DIR)/ft_strtrim.c \
			$(SRC_DIR)/ft_split.c \
			$(SRC_DIR)/ft_itoa.c \
			$(SRC_DIR)/ft_strmapi.c \
			$(SRC_DIR)/ft_striteri.c \
			$(SRC_DIR)/ft_putchar_fd.c \
			$(SRC_DIR)/ft_putstr_fd.c \
			$(SRC_DIR)/ft_putendl_fd.c \
			$(SRC_DIR)/ft_putnbr_fd.c \
			$(SRC_DIR)/ft_strcat.c \
			$(SRC_DIR)/ft_stringlcopy.c \
			$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_print_hex.c \
			$(SRC_DIR)/ft_print_nbr.c \
			$(SRC_DIR)/ft_print_ptr.c \
			$(SRC_DIR)/ft_print_str.c \
			$(SRC_DIR)/ft_print_unbr.c 

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

SRCS_BONUS = $(SRC_DIR_BONUS)/ft_lstnew_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstadd_front_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstsize_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstlast_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstadd_back_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstclear_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstiter_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstmap_bonus.c \
			$(SRC_DIR_BONUS)/ft_lstdelone_bonus.c \
			$(SRC_DIR_BONUS)/get_next_line_bonus.c \
			$(SRC_DIR_BONUS)/get_next_line_utils_bonus.c

OBJS_BONUS = $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(BUILD_DIR)/%.o)

all: header $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) && echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_MKD) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR_BONUS)/%.c
	$(DIR_MKD) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

header:
	${info }
	${info ${BOLD}Creating ->${YELLOW}$(NAME)${NO_COLOR}}
	@if $(MAKE) -q $(NAME) ; then \
					echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME)${NO_COLOR}"; \
					fi

.PHONY: all clean fclean re bonus
.SILENT:

YELLOW			:=${shell tput setaf 3}
GREEN			:=${shell tput setaf 2}
RED				:=${shell tput setaf 1}
NO_COLOR		:=${shell tput sgr0}
BOLD			:=${shell tput bold}