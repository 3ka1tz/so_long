NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L minilibx-linux -lmlx -lX11 -lXext -lm

MLX = minilibx-linux/libmlx_Linux.a

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

all: $(NAME)
	@echo "${GREEN}$(NAME) has been successfully built.${RESET}"
	@$(MAKE) -s usage

$(NAME): mlx $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(MLX)

src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

mlx:
	@$(MAKE) -s -C minilibx-linux > /dev/null 2>&1
	@echo "${GREEN}minilibx-linux has been successfully built.${RESET}"

clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C minilibx-linux clean > /dev/null 2>&1
	@echo "${GREEN}Cleaned up object files and dependencies.${RESET}"

fclean: clean
	@rm -f $(NAME)
	@echo "${GREEN}Fully cleaned up all build artifacts.${RESET}"

re: fclean all

usage:
	@echo "${YELLOW}Usage: ./so_long map.ber${RESET}"

.PHONY: all clean fclean re mlx usage