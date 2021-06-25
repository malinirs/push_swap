#include "push_swap.h"

static void	sorted_array(int *sort, int n)
{
	int 	i;
	int		j;
	int 	temp;

	j = 1;
	while (sort[j] && j < n)
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

	i = 0;
	while (sort[i] && i < n)
	{
		printf("%d ", sort[i]);
		i++;
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

void	rules_swap(t_list **list)
{
	t_list	*swap;
	int		*sort;
	int n = ft_lstsize(*list);




	sort = create_int_array(list);
	sorted_array(sort, n);


//	sa(list);
	pb(list, &swap);
//	pb(list, &swap);
//	pb(list, &swap);
//	sb(&swap);
//	ss(list, &swap);
//	pa(list, &swap);
//	pb(list, &swap);
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
	free(sort);
//	free_list(&push);
}
