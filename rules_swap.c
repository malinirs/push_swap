/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:54:12 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:54:16 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorted_array(int *arr, t_size *len)
{
	int		i;
	int		j;
	int		temp;

	j = 1;
	while (j <= len->size_a)
	{
		temp = arr[j];
		i = j - 1;
		while (temp < arr[i] && i >= 0)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = temp;
		j++;
	}
}

static int	*create_int_array(t_list **list)
{
	t_list	*t;
	int		*sort;
	int		i;
	int		n;

	i = 0;
	t = *list;
	n = ft_lstsize(t);
	sort = malloc(sizeof(int) * n);
	if (!sort)
		clear_list(list);
	while (n > i++)
	{
		sort[i] = t->nbr;
		t = t->next;
	}
	return (sort);
}

static void	write_order(t_list **list, int *sort, t_size *len)
{
	t_list	*temp;
	int		i;

	temp = *list;
	while (temp != NULL)
	{
		i = 0;
		while (i <= len->size_a)
		{
			if (temp->nbr == sort[i])
			{
				temp->order = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

static t_size	init(t_list *list, t_list *swap)
{
	t_size	len;

	len.size_a = ft_lstsize(list);
	len.size_b = ft_lstsize(swap);
	len.i_index = 0;
	len.i_greater = 0;
	return (len);
}

void	rules_swap(t_list **list)
{
	t_list	*swap;
	int		*sort;
	t_size	len;

	swap = NULL;
	len = init(*list, swap);
	check_sort(list, &len);
	sort = create_int_array(list);
	sorted_array(sort, &len);
	write_order(list, sort, &len);
	free(sort);
	markup_mode(list, &len);
	check_keep_A(list, &swap, &len);
	free_list(list);
}
