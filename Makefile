SRCS		= server.c client.c ft_printf/ft_printf.c ft_atoi.c ft_printf/utils.c

OBJS		= $(SRCS:.c=.o)

.o : .c
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
