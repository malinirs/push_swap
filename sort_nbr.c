#include "push_swap.h"

void	ra(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next; /** a[i] = a[i + 1] */
	ft_lstadd_back(list, tmp);
	tmp->next = NULL;

	tmp = *list;
	printf("\n");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
}

void	sort_nbr(t_list **list)
{
	ra(list);
}