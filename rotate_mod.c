/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:39 by awoods            #+#    #+#             */
/*   Updated: 2021/08/18 15:15:41 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_mod(t_list **list, t_size *len)
{
	t_list	*tmp;

	if (len->size_a > 1)
	{
		tmp = *list;
		*list = (*list)->next;
		ft_lstadd_back(list, tmp);
		tmp->next = NULL;
	}
}

void	rb_mod(t_list **swap, t_size *len)
{
	t_list	*b;

	if (len->size_b > 1)
	{
		b = *swap;
		*swap = (*swap)->next;
		ft_lstadd_back(swap, b);
		b->next = 0x0;
	}
}

void	rr_mod(t_list **list, t_list **swap, t_size *len)
{
	ra_mod(list, len);
	rb_mod(swap, len);
}
