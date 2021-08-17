/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:55:47 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:55:50 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *list;
	b = a->next;
	c = b->next;
	*list = b;
	b->next = a;
	a->next = c;
	write(1, "sa\n", 3);
}

void	sb(t_list **swap)
{
	t_list	*b;

	b = *swap;
	*swap = (*swap)->next;
	b->next = (*swap)->next;
	(*swap)->next = b;
	write(1, "sb\n", 3);
}

void	ss(t_list **list, t_list **swap)
{
	sa(list);
	sb(swap);
}

void	pa(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;

	a = *list;
	b = *swap;
	*swap = (*swap)->next;
	b->next = a;
	*list = b;
	write(1, "pa\n", 3);
	len->size_a = len->size_a + 1;
	len->size_b = len->size_b - 1;
}

void	pb(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;

	a = *list;
	b = *swap;
	*list = (*list)->next;
	a->next = b;
	*swap = a;
	write(1, "pb\n", 3);
	len->size_a = len->size_a - 1;
	len->size_b = len->size_b + 1;
}
