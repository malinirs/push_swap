#include "push_swap.h"

void	ra(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next; /** a[i] = a[i + 1] */
	ft_lstadd_back(list, tmp);
	tmp->next = NULL;


//	write(1, "ra\n", 3);
	printf("\nra ");
//	tmp = *list;
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}
}

void	rb(t_list **swap)
{
	t_list	*b;

//	b = *swap;
//	printf("\n");
//	while(b != NULL)
//	{
//		printf("%d ", b->nbr);
//		b = b->next;
//	}

	b = *swap;
	*swap = (*swap)->next;
	ft_lstadd_back(swap, b);
	b->next = 0x0;

	printf("\nrb ");
//	write(1, "rb\n", 3);
//	b = *swap;
//	while(b != NULL)
//	{
//		printf("%d ", b->nbr);
//		b = b->next;
//	}
}

void	rr(t_list **list, t_list **swap)
{
	ra(list);
	rb(swap);
}
