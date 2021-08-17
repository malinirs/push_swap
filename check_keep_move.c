/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keep_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:12:43 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 11:12:46 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	realize_move_contin(t_list **list, t_list **swap, t_list *min)
{
	if ((min)->ra == 1)
	{
		while (min->step_A-- > 0)
			ra(list, 1);
	}
	else if ((min)->rra == 1)
	{
		while (min->step_A-- > 0)
			rra(list, 1);
	}
	if ((min)->rb == 1)
	{
		while (min->step_B-- > 0)
			rb(swap, 1);
	}
	else if ((min)->rrb == 1)
	{
		while (min->step_B-- > 0)
			rrb(swap, 1);
	}
}

void	realize_move(t_list **list, t_list **swap, t_list *min)
{
	if ((min)->ra == 1 && (min)->rb == 1)
	{
		while (min->step_B > 0 && min->step_A > 0)
		{
			rr(list, swap);
			min->step_B--;
			min->step_A--;
		}
	}
	if ((min)->rra == 1 && (min)->rrb == 1)
	{
		while (min->step_B > 0 && min->step_A > 0)
		{
			rrr(list, swap);
			min->step_B--;
			min->step_A--;
		}
	}
	realize_move_contin(list, swap, min);
}

int	search_min(t_list *list)
{
	t_list	*a;
	int		min;
	int		min_i;
	int		i;

	i = 0;
	a = list;
	min = a->nbr;
	min_i = 0;
	while (a)
	{
		if (min > a->nbr)
		{
			min = a->nbr;
			min_i = i;
		}
		i++;
		a = a->next;
	}
	return (min_i);
}

void	transition_min_nbr(t_list **list, t_size *len)
{
	t_list	*a;
	int		i;
	int		min;

	a = *list;
	i = 0;
	min = search_min(*list);
	while (i++ < min)
		a = a->next;
	if (--i > len->size_a / 2 + len->size_b % 2)
	{
		i = len->size_a - i;
		while (i-- > 0)
			rra(list, 1);
	}
	else
		while (i-- > 0)
			ra(list, 1);
}
