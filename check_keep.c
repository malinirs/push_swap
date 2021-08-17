/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:37:17 by awoods            #+#    #+#             */
/*   Updated: 2021/08/16 20:37:19 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	keep_A_index_contin(t_list *head, t_list **temp, int i)
{
	while (*temp != head)
	{
		if ((*temp)->order == i)
		{
			(*temp)->keep_A = 1;
			i++;
		}
		else
			(*temp)->keep_A = 0;
		*temp = (*temp)->next;
	}
}

void	keep_A_index(t_list **list, t_list *head)
{
	t_list	*temp;
	int		i;

	temp = head;
	i = temp->order + 1;
	while (temp != NULL)
	{
		if (temp->order == i)
		{
			temp->keep_A = 1;
			i++;
		}
		else
			temp->keep_A = 0;
		temp = temp->next;
	}
	temp = *list;
	keep_A_index_contin(head, &temp, i);
	temp->keep_A = 1;
}

static int	check_zero(t_list *list)
{
	while (list != NULL)
	{
		if (list->keep_A == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

void	check_keep_A(t_list **list, t_list **swap, t_size *len)
{
	t_list	*min;

	while (check_zero(*list))
	{
		if ((*list)->keep_A == 0)
			pb(list, swap, len);
		else
			ra(list, 1);
	}
	while (*swap)
	{
		check_step_B(swap, len);
		check_step_A(list, swap, len);
		min = summ_step(swap);
		realize_move(list, swap, min);
		pa(list, swap, len);
	}
	transition_min_nbr(list, len);
}
