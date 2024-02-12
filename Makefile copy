NAME = client
NAME2 = server
NAME_BONUS = client_bonus
NAME2_BONUS = server_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = client.c server.c utils.c
SRC2 = client_bonus.c server_bonus.c utils_bonus.c
OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all : client server

$(NAME) : client.o utils.o minitalk.h
	$(CC) $(CFLAGS) client.c utils.c -o client

$(NAME2) : server.o utils.o minitalk.h
	$(CC) $(CFLAGS) server.c utils.c -o server

bonus : client_bonus server_bonus

client_bonus : client_bonus.o utils_bonus.o minitalk_bonus.h
	$(CC) $(CFLAGS) client_bonus.c utils_bonus.c -o client_bonus

server_bonus : server_bonus.o utils_bonus.o minitalk_bonus.h
	$(CC) $(CFLAGS) server_bonus.c utils_bonus.c -o server_bonus

clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME_BONUS) $(NAME2_BONUS)

re: fclean all
