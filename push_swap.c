#include "push_swap.h"

static int  check_str(char *str)
{
	int    i;
	int    di;

	i = 0;
	di = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) > 0)
	{
		i++;
		di++;
	}
	if (!str[i] && di)
		di = 1;
	else
		di = 0;
	return (di);
}

static void	write_element(t_list **list, char *str)
{
	int			number;
	t_list	*tmp;
	int    di;

	di = check_str(str);
	if (!di)
		clear_list(list);
	number = ft_atoi_mod(str);
	if (number > 2147483647 || number < -2147483648)
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
	int		di;

	ptr = ft_split(str, ' ');
	q = ptr;
	while (*q)
	{
		di = check_str(*q);
		if (!di)
			clear_list(list);
		number = ft_atoi_mod(*q);
		if (number >= 2147483647 || number <= -2147483648)
			clear_list(list);
		tmp = ft_lstnew(number);
		if (!tmp)
			clear_list(list);
		ft_lstadd_back(list, tmp);
		q++;
	}
}

void 	write_list(char **argv, t_list **list)
{
	while (*argv)
	{
		if (!ft_strchr_mod(*argv, ' '))
			write_element(list, *argv);
		else
			write_elem_space(list, *argv);
		argv++;
	}
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
	t_list	*list;
	char	**temp;

	argv++;
	argc--;
	if (argc > 0)
	{
		temp = argv;
		list = 0x0;
		write_list(temp, &list);
		check_duplicat(&list);
		rules_swap(&list);
	}
	if (argc <= 0)
		close_program();
//	while (1)
//		;
	return (0);
}
