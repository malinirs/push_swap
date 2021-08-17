/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keep_contin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:54:40 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 10:54:43 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_min_step(t_list **swap)
{
	t_list	*b;
	int		min;
	int		min_i;
	int		i;

	i = 0;
	b = *swap;
	min = b->sum_step;
	min_i = 0;
	while (b)
	{
		if (min > b->sum_step)
		{
			min = b->sum_step;
			min_i = i;
		}
		i++;
		b = b->next;
	}
	return (min_i);
}

t_list	*summ_step(t_list **swap)
{
	t_list	*b;
	int		min_i;
	t_list	*min_B;

	b = *swap;
	while (b)
	{
		b->sum_step = b->step_A + b->step_B;
		b = b->next;
	}
	min_i = search_min_step(swap);
	min_B = *swap;
	while (min_i > 0)
	{
		min_i--;
		min_B = min_B->next;
	}
	return (min_B);
}
