/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_contin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:37:37 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:37:40 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	close_program(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	clear_list(t_list **list)
{
	free_list(list);
	close_program();
}

static int	check_check_duplicat(t_list *list, int nbr, int coun)
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

void	check_duplicat(t_list **list)
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

void	check_sort(t_list **list, t_size *len)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = *list;
	while (temp->next)
	{
		if (temp->nbr < temp->next->nbr)
			count++;
		temp = temp->next;
	}
	if (count == len->size_a - 1)
	{
		free_list(list);
		exit(0);
	}
}
