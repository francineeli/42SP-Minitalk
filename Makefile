NAME = Minitalk

PATH_LIBFT = includes/libft/

INCLUDES = -I $(PATH_LIBFT)

SERVER = server
SERVER_SRCS = sources/server.c
SERVER_OBJS = 	$(SERVER_SRCS:.c=.o)

CLIENT = client
CLIENT_SRCS = sources/client.c
CLIENT_OBJS = 	$(CLIENT_SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

RM = rm -rf
all: libft $(NAME)

libft:
	make -C $(PATH_LIBFT) 

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $< -o $@ -L$(PATH_LIBFT) -lft

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $< -o $@ -L$(PATH_LIBFT) -lft

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	make clean -C $(PATH_LIBFT)

fclean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(SERVER) $(CLIENT)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all clean fclean re
