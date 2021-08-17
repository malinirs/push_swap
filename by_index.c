/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:36:28 by awoods            #+#    #+#             */
/*   Updated: 2021/08/16 20:36:30 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	comparison_A(t_list *t, t_list *list, t_size *len)
{
	t_list	*temp;

	len->count = 0;
	temp = t;
	len->i = t->order + 1;
	while (temp != NULL)
	{
		if (temp->order == len->i)
		{
			len->count++;
			len->i++;
		}
		temp = temp->next;
	}
	temp = list;
	while (temp != t)
	{
		if (temp->order == len->i)
		{
			len->count++;
			len->i++;
		}
		temp = temp->next;
	}
	return (len->count);
}

int	by_index(t_list **list, t_size *len, int *mass)
{
	t_list	*temp;
	int		i;

	temp = *list;
	i = 0;
	while (temp != NULL)
	{
		mass[i] = comparison_A(temp, *list, len) + 1;
		temp = temp->next;
		i++;
	}
	len->index = selection(mass, len);
	i = 0;
	while (mass[i] != len->index[0])
		i++;
	return (i);
}

static void	keep_A_greater_contin(t_size *len, t_list **a, t_list **b)
{
	len->count = 0;
	while (len->count++ < len->i_greater)
	{
		if ((*b)->nbr > (*a)->nbr)
		{
			(*a)->keep_A = 1;
			(*a) = (*b);
		}
		else
			(*a)->keep_A = 0;
		(*b) = (*b)->next;
	}
	(*a)->keep_A = 1;
}

void	keep_A_greater(t_list **list, t_size *len)
{
	t_list	*a;
	t_list	*b;

	b = *list;
	len->count = 0;
	while (len->count < len->i_greater)
	{
		len->count++;
		b = b->next;
	}
	a = b;
	b = b->next;
	while (b != NULL)
	{
		if (b->nbr > a->nbr)
		{
			a->keep_A = 1;
			a = b;
		}
		else
			a->keep_A = 0;
		b = b->next;
	}
	b = *list;
	keep_A_greater_contin(len, &a, &b);
}
