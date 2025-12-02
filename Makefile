NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -lX11 -lXext -lm

MLX = minilibx-linux/libmlx_Linux.a

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

all: $(NAME)
	@echo
	@echo "${GREEN}$(NAME) is ready to be played!${RESET}"
	@echo "${YELLOW}Usage: ./${NAME} <map.ber>${RESET}"
	@echo

$(NAME): mlx $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(MLX)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

mlx:
	@$(MAKE) -s -C minilibx-linux > /dev/null 2>&1
	@echo "${GREEN}minilibx-linux has been successfully built.${RESET}"

clean:
	rm -f $(OBJS)
	@$(MAKE) -s -C minilibx-linux clean > /dev/null 2>&1

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
