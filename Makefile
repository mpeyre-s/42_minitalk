NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

LIBFT = ./includes/libft.a
INCLUDES = ./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT) $(LIBFT) -I $(INCLUDES)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER) $(LIBFT) -I $(INCLUDES)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(SRC_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(SRC_CLIENT_BONUS) $(LIBFT) -I $(INCLUDES)

$(NAME_SERVER_BONUS): $(SRC_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(SRC_SERVER_BONUS) $(LIBFT) -I $(INCLUDES)

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
