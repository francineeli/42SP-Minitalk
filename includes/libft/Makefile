NAME = libft.a

INCLUDE = libft.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c  ft_printchar.c \
			ft_printf.c ft_printhex.c ft_printint.c ft_printptr.c ft_printstr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_utoa.c


OBJS = 		ft_atoi.o ft_bzero.o ft_calloc.o ft_isdigit.o ft_printchar.o \
			ft_printf.o ft_printhex.o ft_printint.o ft_printptr.o ft_printstr.o \
			ft_putchar_fd.o ft_putstr_fd.o ft_strlen.o ft_utoa.o

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ): $(SRCS)
	$(CC) $(FLAGS) -I $(INCLUDE) -c $(SRCS)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
