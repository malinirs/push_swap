#include "push_swap.h"

static int	check_duplicates(int size, int quantity)
{
	int 	*arr;

	arr = malloc(sizeof(int) * size * quantity);
	if (!arr)
		return (0);
	return (1);
}

static int	check_str(int argc, char **argv)
{
	int		quantity;
	int		i;
	int		j;

	i = 0;
	j = -1;
	quantity = 0;
	argc--;
	while (argv[argc][i] && ++j <= argc)
	{
		while (argv[j][i])
		{
			if (!ft_isdigit_mod(argv[j][i]))
				close_program();
			if (ft_strlen(argv[j]) == 1 && (argv[j][i] == '-' || \
			argv[j][i] == '+'))
				close_program();
			if (ft_strlen(argv[j]) > 1 && ((argv[j][i] == '+' ||
			argv[j][i] == '-' || argv[j][i] == ' ') && \
			ft_isdigit_mod(argv[j][i])))
				close_program();
			quantity++;
			i++;
		}
//		j++;
		i = 0;
	}

	printf("quantity = %d\n", quantity);

	return (quantity);
}

t_list 	write_list(char **argv, t_list **list, int quantity)
{
	t_list	*tmp;
	int		number;
	int		size;

	while (*argv)
	{
		number = ft_atoi_mod(*argv);
		if (number >= INT32_MAX || number <= INT32_MIN)
			clear_list(list);
		tmp = ft_lstnew(number);
		ft_lstadd_back(list, tmp);
		// написать функцию для заполнения arr
		argv++;
	}
	size = ft_lstsize(*list);
	if (!check_duplicates(size, quantity));
		clear_list(list);


	tmp = *list;
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
	return (**list);
}

int main(int argc, char **argv)
{
	t_list	**list;
	int		quantity; /** количество всех цифр */

	if (argc > 1)
	{
		argv++;
		argc--;
		quantity = check_str(argc, argv);
		list = malloc(sizeof(t_list *));
		*list = 0x0;
		write_list(argv, list, quantity);
		sort_nbr(list);
	}
	else
		close_program();
	return (0);
}
