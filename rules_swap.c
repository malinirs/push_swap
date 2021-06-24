#include "push_swap.h"

void	rules_swap(t_list **list)
{
	t_list	*swap;
//	t_list	*tmp;

//	sa(list);
	pb(list, &swap);
	pb(list, &swap);
	pb(list, &swap);
//	sb(&swap);
//	ss(list, &swap);
//	pa(list, &push);
//	pb(list, &push);
//	ra(list);
//	rb(&swap);
//	rr(list, &swap);
//	rra(list);
//	rrb(&swap);
	rrr(list, &swap);

//	tmp = *list;
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}

	free_list(list);
//	free_list(&push);
}
