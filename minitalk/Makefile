OBJ_SERV = server.c utils_serv.c
OBJ_CLIENT = client.c utils_client.c
SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

EXCH_CLIENT = $(patsubst %.c,%.o,$(OBJ_CLIENT))
EXCH_SERV = $(patsubst %.c,%.o,$(OBJ_SERV))

all : $(SERVER) $(CLIENT)

$(SERVER) : $(EXCH_SERV)
	@$(CC) $(FLAGS) $(EXCH_SERV)  -o $@

$(CLIENT) : $(EXCH_CLIENT)
	@$(CC) $(FLAGS) $(EXCH_CLIENT) -o $@

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	@rm -f *.o

fclean: clean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all