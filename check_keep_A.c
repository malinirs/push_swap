#include "push_swap.h"

int	check_zero(t_list *list)
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
	while (check_zero(*list))
	{
//		if ()
//			sa(list);
		if ((*list)->keep_A == 0)
			pb(list, swap, len);
		ra(list);
	}

	t_list *tmp = *list;
	printf("\nlist: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
	tmp = *swap;
	printf("\nswap: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
}

