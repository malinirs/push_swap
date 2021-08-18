NAME = push_swap
HEADER	= push_swap.h
NAME_B = checker

SRCS =	by_index.c \
		check_keep.c \
		check_keep_contin.c \
		check_step_A_B.c \
		check_keep_move.c \
		markup_mode.c \
		geater_than.c \
		push_swap.c \
		push_swap_contin.c \
		rotate.c \
		reverse_rotate.c \
		utils.c \
		list.c \
		rules_swap.c \
		ft_split.c \
		swap_and_push.c

SRCS_B =	checker.c \
			ft_split.c \
			push_swap_contin.c \
			utils.c \
			list.c \
			rotate_mod.c \
     		reverse_rotate_mod.c \
    	    push_and_swap_mod.c \
    	    checker_contin.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	gcc $(SRCS) -o $(NAME)

bonus : $(OBJS_B) $(HEADER)
	gcc $(SRCS_B) -o $(NAME_B)

%.o : %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

clean   :
	rm -f *.o

fclean	:	clean
	rm -f $(NAME) $(NAME_B)

re		:	fclean all bonus

.PHONY	:	all clean fclean re bonus
