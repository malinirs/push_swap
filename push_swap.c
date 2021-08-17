/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:37:28 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:37:30 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) > 0)
	{
		i++;
		flag++;
	}
	if (!str[i] && flag)
		flag = 1;
	else
		flag = 0;
	return (flag);
}

static void	write_element(t_list **list, char *str)
{
	long	number;
	t_list	*tmp;
	int		flag;

	flag = check_str(str);
	if (!flag)
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
	long	number;
	t_list	*tmp;
	char	**ptr;
	char	**q;
	int		flag;

	ptr = ft_split(str, ' ');
	if (ptr == NULL)
		clear_list(list);
	q = ptr;
	while (*q)
	{
		flag = check_str(*q);
		if (!flag)
			clear_list(list);
		number = ft_atoi_mod(*q);
		if (number > 2147483647 || number < -2147483648)
			clear_list(list);
		tmp = ft_lstnew(number);
		if (!tmp)
			clear_list(list);
		ft_lstadd_back(list, tmp);
		q++;
	}
}

static void	write_list(char **argv, t_list **list)
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

int	main(int argc, char **argv)
{
	t_list	*list;
	char	**temp;

	argv++;
	argc--;
	if (argc < 1)
		close_program();
	else if (argc > 0)
	{
		temp = argv;
		list = 0x0;
		write_list(temp, &list);
		check_duplicat(&list);
		rules_swap(&list);
	}
	return (0);
}
