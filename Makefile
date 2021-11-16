NAME		= libftprintf.a

SRCS		= Printf/ft_printf.c\
			Printf/ft_prints.c\
			Printf/ft_check_format.c\
			Printf/ft_check_wp.c\
			Printf/ft_utils.c\
			Printf/ft_utils2.c\
			Printf/ft_prints2.c\
			Printf/ft_utils3.c\
			Printf/ft_utils4.c\

OBJS		=$(SRCS:%.c=%.o)

CC			= gcc

LC			= ar -rcs

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

Printf/%.o:		Printf/%.c Printf/ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(LC) $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re