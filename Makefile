NAME_CLIENT = client
NAME_SERVER = server

SRC_CLIENT = client.c
SRC_SERVER = server.c

LIBFT = ./includes/libft.a
INCLUDES = ./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT) $(LIBFT) -I $(INCLUDES)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER) $(LIBFT) -I $(INCLUDES)

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
