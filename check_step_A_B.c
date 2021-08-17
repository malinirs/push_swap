/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_step_A_B.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:01:31 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 11:01:33 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_position_contin(t_list *list, t_list *swap, t_size *len)
{
	len->i = 0;
	while (len->i < len->min)
	{
		if (swap->nbr < list->nbr)
			return (len->i);
		list = list->next;
		len->i++;
	}
	return (len->i);
}

static int	search_position(t_list *list, t_list *swap, t_size *len)
{
	t_list	*a;

	len->i = 0;
	a = list;
	len->min = search_min(list);
	while (len->i++ < len->min)
		a = a->next;
	if (a->nbr > swap->nbr)
		return (len->min);
	len->i = 0;
	while (a)
	{
		if (swap->nbr < a->nbr)
			return (len->i + len->min);
		a = a->next;
		len->i++;
	}
	len->i = search_position_contin(list, swap, len);
	return (len->i);
}

void	check_step_A(t_list **list, t_list **swap, t_size *len)
{
	t_list	*b;
	int		position;

	b = *swap;
	while (b)
	{
		b->ra = 0;
		b->rra = 0;
		position = search_position(*list, b, len);
		if (position == len->size_a)
			position = search_min(*list);
		if (position > 0 && position <= len->size_a / 2 + len->size_b % 2)
			b->ra = 1;
		else if (position > len->size_a / 2 + len->size_b % 2)
		{
			position = len->size_a - position;
			b->rra = 1;
		}
		b->step_A = position;
		b = b->next;
	}
}

void	check_step_B(t_list **swap, t_size *len)
{
	t_list	*b;
	int		i;

	i = 0;
	b = *swap;
	while (i < (len->size_b / 2 + len->size_b % 2))
	{
		b->rb = 1;
		b->rrb = 0;
		b->step_B = i;
		b = b->next;
		i++;
	}
	while (b)
	{
		b->rb = 0;
		b->rrb = 1;
		b->step_B = len->size_b - i;
		i++;
		b = b->next;
	}
}
