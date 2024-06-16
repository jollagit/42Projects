NAME		:= so_long
LIBFT		:= libft/libft.a
CC			:= cc
LIB			:= ft
CFLAGS		:= -Wall -Wextra -Werror -I./include

# COntains the X11 and MLX header files
INCLUDES 	:= -I/usr/include -Imlx_linux

# Link X11 and MLX
MLX_FLAGS = -L./mlx_linux -lmlx -L/usr/lib/X11 -lXext -lX11

RM			:= rm -rf

BUILD_DIR	:= .build
SRC_DIR		:= src
DIR_MKD		:= mkdir -p $(@D)

SRCS		:= $(SRC_DIR)/main.c \
			$(SRC_DIR)/so_long.c \
			$(SRC_DIR)/put_image.c \
			$(SRC_DIR)/so_long_utils.c \
			$(SRC_DIR)/search_str_image.c

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

LDFLAGS		:= $(addprefix -L,$(dir $(LIBFT)))
LDLIB		:= $(addprefix -l,$(LIB))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(@D)
	$(MAKE) bonus -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_MKD) $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	$(RM) $(BUILD_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean