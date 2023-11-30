CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = tinyhttppd.out
SRCS = ./tinyhttppd/main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(OBJS) : 
	$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)
fclean :
	rm -f $(NAME) 

re : clean fclean all

.PHONY : all clean fclean re
