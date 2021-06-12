#include "push_swap.h"

static int	check_duplicates(int number)
{
	if (number)
	return (1);
}

static void	check_str(char **argv)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (argv[j][i])
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_isdigit(argv[j][i])) /** как пропустить отриц число? */
				close_program();
			i++;
		}
		j++;
	}
}

t_list 	write_list(char **argv, t_list **list)
{
	t_list	*tmp;
	int		number;

	while (*argv)
	{
		number = ft_atoi(*argv, list);
		if (!check_duplicates(number)) /** где лучше сделать проверку на
 										* дубликанты? */
			close_program();
		tmp = ft_lstnew(number);
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

int main(int argc, char **argv)
{
	t_list	**list;

	if (argc > 1)
	{
		argv++;
		check_str(argv);
		list = malloc(sizeof(t_list *));
		*list = 0x0;
		write_list(argv, list);
		sort_nbr(list);
	}
	else
		close_program();
	return (0);
}
