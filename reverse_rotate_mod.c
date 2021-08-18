/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:19 by awoods            #+#    #+#             */
/*   Updated: 2021/08/18 15:15:20 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_mod(t_list **list, t_size *len)
{
	t_list	*temp;
	int		count;

	if (len->size_a > 1)
	{
		temp = *list;
		count = -1;
		while (*list != NULL && ++count < (ft_lstsize(temp) - 1))
			*list = (*list)->next;
		(*list)->next = temp;
		temp = *list;
		while (temp != NULL && 0 < count--)
			temp = temp->next;
		temp->next = NULL;
	}
}

void	rrb_mod(t_list **swap, t_size *len)
{
	t_list	*b;
	int		count;
	int		i;

	if (len->size_b > 1)
	{
		b = *swap;
		i = -1;
		count = ft_lstsize(b) - 1;
		while (*swap != NULL && count > ++i)
			*swap = (*swap)->next;
		(*swap)->next = b;
		b = *swap;
		while (b != NULL && count-- > 0)
			b = b->next;
		b->next = NULL;
	}
}

void	rrr_mod(t_list **list, t_list **swap, t_size *len)
{
	rra_mod(list, len);
	rrb_mod(swap, len);
}
