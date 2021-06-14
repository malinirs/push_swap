#include "push_swap.h"

static void	check_str(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
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
			i++;
		}
//		j++;
		i = 0;
	}
}

t_list 	write_list(char **argv, t_list **list)
{
	t_list	*tmp;
	int		number;

	while (*argv)
	{
		number = ft_atoi_mod(*argv);
		if (number >= INT32_MAX || number <= INT32_MIN)
			clear_list(list);
		tmp = ft_lstnew(number);
		if (!tmp)
			clear_list(list);
		ft_lstadd_back(list, tmp);
		argv++;
	}

	tmp = *list;
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
	return (**list);
}

static int	duplicat(int *arr, int number, int j)
{
	int		i;

	i = 0;
	while (arr[i] && i < j)
	{
		if (arr[i] == number)
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicat(int size_list, char **argv)
{
	int		*arr;
	int		i;
	int		flag;

	i = 0;
	arr = malloc(sizeof(int) * size_list);
	if (!arr)
		return (0x0);
	while (*argv)
	{
		arr[i] = ft_atoi_mod(*argv);
		flag = duplicat(arr, arr[i], i);
		i++;
		argv++;
	}
	free(arr);
	return (flag);
}

int main(int argc, char **argv)
{
	t_list	**list;
	int		size_list;

	if (argc > 1)
	{
		argv++;
		argc--;
		check_str(argc, argv);
		list = malloc(sizeof(t_list *));
		if (!list)
			close_program();
		*list = 0x0;
		write_list(argv, list);
		size_list = ft_lstsize(*list);
		if (!check_duplicat(size_list, argv))
			clear_list(list);
		sort_nbr(list);
	}
	else
		close_program();
	return (0);
}
