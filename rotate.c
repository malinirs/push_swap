#include "push_swap.h"

void	ra(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, tmp);
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **swap)
{
	t_list	*b;

	b = *swap;
	*swap = (*swap)->next;
	ft_lstadd_back(swap, b);
	b->next = 0x0;
	write(1, "rb\n", 3);
}

void	rr(t_list **list, t_list **swap)
{
	ra(list);
	rb(swap);
}
