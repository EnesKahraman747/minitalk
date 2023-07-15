SRCS		= ft_printf.c utils.c

OBJS		= $(SRCS:.c=.o)

.o : .c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
all:        $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
