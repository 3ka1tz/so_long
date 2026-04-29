NAME = so_long

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/argument_validation.c \
       $(SRC_DIR)/exit_game.c \
       $(SRC_DIR)/map_validation.c \
       $(SRC_DIR)/playable_area.c \
       $(SRC_DIR)/player_movement.c \
       $(SRC_DIR)/texture_rendering.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/ft_split.c \
       $(SRC_DIR)/ft_strlen.c \
	   $(SRC_DIR)/ft_strncmp.c \
       $(SRC_DIR)/ft_strndup.c \
	   $(SRC_DIR)/ft_putstr_fd.c

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L libs/minilibx-linux -lmlx -lX11 -lXext -lm

MLX = libs/minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(NAME): mlx $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(FT_PRINTF) $(MLX)

$(FT_PRINTF):
	$(MAKE) -s -C $(FT_PRINTF_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

mlx:
	$(MAKE) -s -C libs/minilibx-linux

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libs/minilibx-linux clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
