NAME = libftprintf.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/ft_printf.c \
       $(SRC_DIR)/printchar.c \
       $(SRC_DIR)/printstr.c \
       $(SRC_DIR)/printptr.c \
       $(SRC_DIR)/printnbr.c \
       $(SRC_DIR)/printhex.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
