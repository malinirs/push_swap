/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:35:12 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:35:15 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	markup_mode_contin(t_list **list, t_size *len, int *arr, int *mass)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *list;
	if (arr[len->i_greater] > mass[len->i_index])
		keep_A_greater(list, len);
	else
	{
		while (i++ < len->i_index)
			temp = temp->next;
		keep_A_index(list, temp);
	}
}

void	markup_mode(t_list **list, t_size *len)
{
	int		*arr;
	int		*mass;

	if (len->size_a == 5)
		check_stack_A_5(list);
	if (len->size_a == 3)
		check_stack_A_3(list);
	arr = malloc(sizeof(int) * len->size_a);
	if (!arr)
	{
		arr = NULL;
		clear_list(list);
	}
	len->i_greater = greater_than(list, len, arr);
	mass = malloc(sizeof(int) * len->size_a);
	if (!mass)
	{
		mass = NULL;
		clear_list(list);
	}
	len->i_index = by_index(list, len, mass);
	markup_mode_contin(list, len, arr, mass);
	free(arr);
	free(mass);
}
