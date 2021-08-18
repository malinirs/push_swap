/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:16:04 by awoods            #+#    #+#             */
/*   Updated: 2021/08/18 15:16:17 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_mod(t_list **list, t_size *len)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	if (len->size_a > 1)
	{
		a = *list;
		b = a->next;
		c = b->next;
		*list = b;
		b->next = a;
		a->next = c;
	}
}

void	sb_mod(t_list **swap, t_size *len)
{
	t_list	*b;

	if (len->size_b > 1)
	{
		b = *swap;
		*swap = (*swap)->next;
		b->next = (*swap)->next;
		(*swap)->next = b;
	}
}

void	ss_mod(t_list **list, t_list **swap, t_size *len)
{
	sa_mod(list, len);
	sb_mod(swap, len);
}

void	pa_mod(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;

	if (len->size_b > 0)
	{
		a = *list;
		b = *swap;
		*swap = (*swap)->next;
		b->next = a;
		*list = b;
		len->size_a = len->size_a + 1;
		len->size_b = len->size_b - 1;
	}
}

void	pb_mod(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;

	if (len->size_a > 0)
	{
		a = *list;
		b = *swap;
		*list = (*list)->next;
		a->next = b;
		*swap = a;
		len->size_a = len->size_a - 1;
		len->size_b = len->size_b + 1;
	}
}
