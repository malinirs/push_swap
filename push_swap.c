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
			!ft_isdigit_mod(argv[j][++i])))
				close_program();
			i++;
		}
		i = 0;
	}
}

static void	write_element(t_list **list, char *str)
{
	int		number;
	t_list	*tmp;

	number = ft_atoi_mod(str);
	if (number >= INT32_MAX || number <= INT32_MIN)
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

	ptr = ft_split(str, ' ');
	while (*ptr)
	{
		number = ft_atoi_mod(*ptr);
		if (number >= INT32_MAX || number <= INT32_MIN)
			clear_list(list);
		tmp = ft_lstnew(number);
		if (!tmp)
			clear_list(list);
		ft_lstadd_back(list, tmp);
		ptr++;
	}
}

void 	write_list(char **argv, t_list **list)
{
	t_list	*tmp;

	while (*argv)
	{
		if (!ft_strchr_mod(*argv, ' ')) /** нет ' ' */
			write_element(list, *argv);
		else
			write_elem_space(list, *argv);
		argv++;
	}

	tmp = *list;
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
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

//static int	write_arr_space(t_list **list, char *str)
//{
//
//}

static int	check_duplicat(int size_list, char **argv)
{
	int		*arr;
	int		i;
	int		flag;
	char	**ptr;

	i = 0;
	arr = malloc(sizeof(int) * size_list);
	if (!arr)
		return (0x0);
	while (*argv)
	{
		if (!ft_strchr_mod(*argv, ' ')) /** нет ' ' */
		{
			arr[i] = ft_atoi_mod(*argv);
			flag = duplicat(arr, arr[i], i);
		}
		else
		{
			ptr = ft_split(*argv, ' ');
			while (*ptr)
			{
				arr[i] = ft_atoi_mod(*ptr);
				flag = duplicat(arr, arr[i], i);
				ptr++;
				i++;
			}
		}
		i++;
		argv++;
	}
	free(arr);
	return (flag);
}

int main(int argc, char **argv)
{
	t_list	**list;
	char	**temp;

	if (argc > 1)
	{
		argv++;
		argc--;
		temp = argv;
		check_str(argc, temp);
		list = malloc(sizeof(t_list *));
		if (!list)
			close_program();
		*list = 0x0;
		write_list(temp, list);
		if (!check_duplicat(ft_lstsize(*list), temp))
			clear_list(list);
		sort_nbr(list);
	}


//	free(temp);


	if (argc <= 1)
		close_program();
	return (0);
}
