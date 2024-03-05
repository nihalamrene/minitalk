CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_NAME = client
SERVER_NAME = server


SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC = Utils.c

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(SRC_CLIENT) minitalk.h $(SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(SRC_CLIENT) $(SRC)

$(SERVER_NAME): $(SRC_SERVER) minitalk.h $(SRC)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SRC_SERVER) $(SRC)


clean:
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all fclean clean re
