NAME = push_swap.a

SRCS =	push_swap.c \
		utils.c \
		list.c \
		sort_nbr.c

#LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
#	${MAKE} -C ./libft
	ar rc $(NAME) $(OBJS) $(LIBFT)

%.o : %.c libft.h
	gcc $(CFLAGS) -c $< -o $@

clean   :
#	${MAKE} clean -C ./libft
	rm -f *.o

fclean	:	clean
#	${MAKE} fclean -C ./libft
	$(RM) $(NAME)

.PHONY	:	all clean fclean re