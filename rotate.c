/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:50:42 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:50:44 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list, int i)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, tmp);
	tmp->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **swap, int i)
{
	t_list	*b;

	b = *swap;
	*swap = (*swap)->next;
	ft_lstadd_back(swap, b);
	b->next = 0x0;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **list, t_list **swap)
{
	ra(list, 0);
	rb(swap, 0);
	write(1, "rr\n", 3);
}
