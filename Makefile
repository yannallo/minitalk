CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(PRINTF_DIR)
LDLIBS = -L$(PRINTF_DIR)
LDFLAGS = -lftprintf

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CLIENT_SRC = src/client.c
SERVER_SRC = src/server.c

CLIENT_OBJ = src/client.o
SERVER_OBJ = src/server.o

all: $(PRINTF) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) Makefile
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LDFLAGS) $(LDLIBS) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ) Makefile
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LDFLAGS) $(LDLIBS) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
