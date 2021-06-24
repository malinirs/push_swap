#include "push_swap.h"

static void	sorted_array(t_list **list, int *sort, int n)
{
	int		i;
	int 	x;
	int 	j;

	i = 1;
	while (sort[i])
	{
		x = sort[i];
		j = i;
		while (j > 0 && sort[j - 1] > x)
		{
			sort[j] = sort[j - 1];
			j--;
		}
		sort[j] = x;
		i++;
	}

	i = 0;
	while (sort[i])
	{
		printf("%d ", sort[i]);
		i++;
	}
}

//{
//	for i = 2 to n do
//		x = A[i]
//		j = i
//		while (int j > 1 and A[j-1] > x) do
//			A[j] = A[j-1]
//			j = j - 1
//		end while
//		A[j] = x;
//	end for[7]
//}

void	rules_swap(t_list **list)
{
	t_list	*swap;
//	t_list	*tmp;

	t_list	*t;
	int		*sort;
	int		i;
	int		n;

	t = *list;
	n = ft_lstsize(t);
	sort = malloc(sizeof(t_list) * n);
	if (!sort)
		clear_list(list);
	i = 0;
	while (t != NULL)
	{
		sort[i++] = t->nbr;
		t = t->next;
	}
	sorted_array(list, sort, n);


//	sa(list);
//	pb(list, &swap);
//	pb(list, &swap);
//	pb(list, &swap);
//	sb(&swap);
//	ss(list, &swap);
//	pa(list, &push);
//	pb(list, &push);
//	ra(list);
//	rb(&swap);
//	rr(list, &swap);
//	rra(list);
//	rrb(&swap);
//	rrr(list, &swap);
//	tmp = *list;
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}

	free_list(list);
	free(sort);
//	free_list(&push);
}
