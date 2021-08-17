/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:49:47 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:49:50 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **list, int i)
{
	t_list	*temp;
	int		count;

	temp = *list;
	count = -1;
	while (*list != NULL && ++count < (ft_lstsize(temp) - 1))
		*list = (*list)->next;
	(*list)->next = temp;
	temp = *list;
	while (temp != NULL && 0 < count--)
		temp = temp->next;
	temp->next = NULL;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **swap, int t)
{
	t_list	*b;
	int		count;
	int		i;

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
	if (t == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **list, t_list **swap)
{
	rra(list, 0);
	rrb(swap, 0);
	write(1, "rrr\n", 4);
}
