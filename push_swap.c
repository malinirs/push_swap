#include "push_swap.h"

static void	check_str(int argc, char **argv)
{
	int		i;
	int		j;

	j = -1;
	argc--;
	while (argv[argc][i] && ++j <= argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!ft_isdigit_mod(argv[j][i]))
				close_program();
			if (ft_strlen(argv[j]) == 1 && (argv[j][i] == '-' || \
			argv[j][i] == '+'))
				close_program();
			if (ft_strlen(argv[j]) > 1 && ((argv[j][i] == '+' || \
			argv[j][i] == '-') && ((argv[j][++i] == '+' || \
			argv[j][i] == '-'))) && (argv[j][i] != '\0'))
				close_program();
			if (ft_strlen(argv[j]) > 1 && ft_isdigit_mod(argv[j][i]) && \
			(argv[j][++i] == '+' || argv[j][i] == '-') && (argv[j][i] != '\0'))
				close_program();
			i++;
		}
	}
}

static void	write_element(t_list **list, char *str)
{
	int			number;
	t_list	*tmp;

	number = ft_atoi_mod(str);
	if (number > INT32_MAX || number < INT32_MIN)
		clear_list(list);
	tmp = ft_lstnew(number);
	if (!tmp)
		clear_list(list);
	ft_lstadd_back(list, tmp);
}

static void	write_elem_space(t_list **list, char *str)
{
	int		number;
	t_list	*tmp;
	char	**ptr;
	char	**q;
	int		j = 0;

	ptr = ft_split(str, ' ');
	q = ptr;
	while (*q)
	{
		number = ft_atoi_mod(*q);
		if (number >= INT32_MAX || number <= INT32_MIN)
			clear_list(list);
		tmp = ft_lstnew(number);
		if (!tmp)
			clear_list(list);
		ft_lstadd_back(list, tmp);
		q++;
	}
	while (ptr[j])
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
}

void 	write_list(char **argv, t_list **list)
{
//	t_list	*tmp;

	while (*argv)
	{
		if (!ft_strchr_mod(*argv, ' ')) /** нет ' ' */
			write_element(list, *argv);
		else
			write_elem_space(list, *argv);
		argv++;
	}

//	tmp = *list;
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}
}

int 	check_check_duplicat(t_list *list, int nbr, int coun)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		if (list->nbr == nbr && i != coun)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

static void	check_duplicat(t_list **list)
{
	t_list	*duplicat;
	int		coun;

	coun = 0;
	duplicat = *list;
	while (duplicat != NULL)
	{
		if (!check_check_duplicat(*list, duplicat->nbr, coun))
			clear_list(list);
		coun++;
		duplicat = duplicat->next;
	}
}

int main(int argc, char **argv)
{
	t_list	**list;
	char	**temp;

	argv++;
	argc--;
	if (argc > 0)
	{
		temp = argv;
		check_str(argc, temp);
		list = malloc(sizeof(t_list *));
		if (!list)
			close_program();
		*list = 0x0;
		write_list(temp, list);
		check_duplicat(list);
		rules_swap(list);
	}
	if (argc <= 0)
		close_program();
//	while (1)
//		;
	return (0);
}
