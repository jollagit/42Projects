NAME			:= push_swap
NAME_BONUS		:= checker
LIBFT			:= libft/libft.a
CC				:= cc
CFLAGS			:= -Werror -Wextra -Wall -I./include
LIB				:= ft
RM				:= rm -rf

BUILD_DIR		:= .build
BUILD_DIR_BONUS	:= .build_bonus
SRC_DIR			:= src
SRC_DIR_BONUS	:= src_bonus
DIR_MKD			:= mkdir -p $(@D)

SRCS			:= $(SRC_DIR)/algoritm.c \
					$(SRC_DIR)/check_function.c \
					$(SRC_DIR)/main.c \
					$(SRC_DIR)/moves.c \
					$(SRC_DIR)/push_swap_utils.c \
					$(SRC_DIR)/push_swap.c \
					$(SRC_DIR)/sort_algoritm.c \
					$(SRC_DIR)/sort_back_sim.c \
					$(SRC_DIR)/sort_list_back.c

OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

SRCS_BONUS		:=$(SRC_DIR_BONUS)/main.c \
					$(SRC_DIR_BONUS)/check_function_bonus.c \
					$(SRC_DIR_BONUS)/push_swap_bonus.c \
					$(SRC_DIR_BONUS)/push_swap_utils_bonus.c \
					$(SRC_DIR_BONUS)/moves_bonus.c

OBJS_BONUS		:=$(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(BUILD_DIR_BONUS)/%.o)

LDFLAGS			:= $(addprefix -L,$(dir $(LIBFT)))
LDLIB			:= $(addprefix -l,$(LIB))

all : $(LIBFT) header $(NAME)

bonus : $(LIBFT) header_bonus $(NAME_BONUS)

$(LIBFT):
		$(MAKE) -C $(@D)
		$(MAKE) bonus -C $(@D)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
		$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME_BONUS)${NO_COLOR}";

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	$(DIR_MKD) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c 
	$(DIR_MKD) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) clean -C libft
		$(RM) $(BUILD_DIR) $(BUILD_DIR_BONUS)

fclean: clean
		$(MAKE) fclean -C libft
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

header: 
	${info }
	${info ${BOLD}Creating  ->${YELLOW}$(NAME)${NO_COLOR}}
	@if $(MAKE) -q $(NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME)${NO_COLOR}"; \
	fi

header_bonus: 
	${info }
	${info ${BOLD}Creating  ->${YELLOW}$(NAME_BONUS)${NO_COLOR}}
	@if $(MAKE) -q $(NAME_BONUS) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME_BONUS)${NO_COLOR}"; \
	fi

.PHONY: all re clean fclean header
.SILENT:

YELLOW		:= ${shell tput setaf 3}
GREEN		:= ${shell tput setaf 2}
RED			:= ${shell tput setaf 1}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}



