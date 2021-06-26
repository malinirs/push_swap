#include "push_swap.h"

static void	sorted_array(int *sort, t_size	*len)
{
	int 	i;
	int		j;
	int 	temp;

	j = 1;
	while (sort[j] && j < len->size_a)
	{
		i = j;
		temp = sort[j];
		while (temp < sort[i - 1] && i > 0)
		{
			sort[i] = sort[i - 1];
			i--;
		}
		sort[i] = temp;
		j++;
	}
}

static int	*create_int_array(t_list **list)
{
	t_list	*t;
	int		*sort;
	int		i;
	int		n;

	t = *list;
	n = ft_lstsize(t);
	sort = malloc(sizeof(int) * n);
	if (!sort)
		clear_list(list);
	i = 0;
	while (t != NULL)
	{
		sort[i] = t->nbr;
		t = t->next;
		i++;
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
		while (i < len->size_a)
		{
			if (temp->nbr == sort[i])
			{
				temp->order = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}

//	temp = *list;
//	while (temp != NULL)
//	{
//		printf("%d ", temp->order);
//		temp = temp->next;
//	}

}

t_size	init(t_list *list, t_list *swap)
{
	t_size	len;

	len.size_a = ft_lstsize(list);
	len.size_b = ft_lstsize(swap);
	return (len);
}

void	rules_swap(t_list **list)
{
	t_list	*swap;
	int		*sort;
	t_size	len;

	swap = NULL;
	len = init(*list, swap);
	sort = create_int_array(list);
	sorted_array(sort, &len);
	write_order(list, sort, &len);
	geater_than(list, len);


//	sa(list);
//	pb(list, &swap);
//	pb(list, &swap);
//	pb(list, &swap);
//	sb(&swap);
//	ss(list, &swap);
//	pa(list, &swap, &len);
//	pb(list, &swap, &len);
//	ra(list);
//	rb(&swap);
//	rr(list, &swap);
//	rra(list);
//	rrb(&swap);
//	rrr(list, &swap);
//	tmp = swap;
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}

	free_list(list);
	free_list(&swap);
	free(sort);
}
