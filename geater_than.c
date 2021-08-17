/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geater_than.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:18:28 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:18:30 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*selection(int *arr, t_size *len)
{
	int		i;
	int		j;
	int		max;

	j = 0;
	i = j + 1;
	max = arr[j];
	while (arr[i] && i < len->size_a)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			j = i;
		}
		i++;
	}
	return (&arr[j]);
}

static void	comparison_Keep_A(t_list *list, t_size *len)
{
	t_list	*a;
	t_list	*b;

	a = list;
	while (a)
	{
		len->count = 0;
		len->i = 0;
		b = a;
		len->value = b->nbr;
		while (len->size_a > len->i)
		{
			if (b->nbr > len->value)
			{
				len->value = b->nbr;
				len->count++;
			}
			b = b->next;
			if (b == 0x0)
				b = list;
			len->i++;
		}
		a->ind_greater = len->count;
		a = a->next;
	}
}

int	greater_than(t_list **list, t_size *len, int *arr)
{
	t_list	*temp;
	int		i;

	comparison_Keep_A(*list, len);
	i = 0;
	temp = *list;
	while (temp)
	{
		arr[i] = temp->ind_greater + 1;
		temp = temp->next;
		i++;
	}
	len->greater = selection(arr, len);
	i = 0;
	while (arr[i] != len->greater[0])
		i++;
	return (i);
}

void	check_stack_A_5(t_list **list)
{
	if ((*list)->nbr > (*list)->next->nbr && \
	(*list)->next->nbr > (*list)->next->next->nbr && \
	(*list)->next->next->nbr > (*list)->next->next->next->nbr && \
	(*list)->next->next->next->nbr > (*list)->next->next->next->next->nbr)
	{
		ra(list, 1);
		sa(list);
		rra(list, 1);
		sa(list);
		ra(list, 1);
		sa(list);
		ra(list, 1);
		ra(list, 1);
		sa(list);
		exit(0);
	}
}

void	check_stack_A_3(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->nbr;
	b = (*list)->next->nbr;
	c = (*list)->next->next->nbr;
	if (a < b && a < c && b > c && c > a)
	{
		sa(list);
		ra(list, 1);
	}
	else if (a > b && b > c && a > c)
	{
		ra(list, 1);
		sa(list);
	}
	else if (a > b && b < c && a > c)
		ra(list, 1);
	else if (a > b && b < c && a < c)
		sa(list);
	else if (c < b && b > a)
		rra(list, 1);
	exit(0);
}
