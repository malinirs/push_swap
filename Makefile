NAME = push_swap.a

SRCS =	push_swap.c \
		utils.c \
		ft_split_mod.c \
		list.c \
		sort_nbr.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c libft.h
	gcc $(CFLAGS) -c $< -o $@

clean   :
	rm -f *.o

fclean	:	clean
	$(RM) $(NAME)

re	    :	fclean all

.PHONY	:	all clean fclean re