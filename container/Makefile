SRCS	=	src/main.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-W -Wextra -Wall -Werror -I./include

NAME	=	container

all:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re