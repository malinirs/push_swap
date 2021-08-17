
#include "push_swap.h"

void	sa_mod(t_list **list, int i)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *list;
	b = a->next;
	c = b->next;
	*list = b;
	b->next = a;
	a->next = c;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb_mod(t_list **swap, int i)
{
	t_list	*b;

	b = *swap;
	*swap = (*swap)->next;
	b->next = (*swap)->next;
	(*swap)->next = b;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss_mod(t_list **list, t_list **swap)
{
	sa_mod(list, 0);
	sb_mod(swap, 0);
}

void	pa_mod(t_list **list, t_list **swap, int i)
{
	t_list	*a;
	t_list	*b;

	a = *list;
	b = *swap;
	*swap = (*swap)->next;
	b->next = a;
	*list = b;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb_mod(t_list **list, t_list **swap, int i)
{
	t_list	*a;
	t_list	*b;

	a = *list;
	b = *swap;
	*list = (*list)->next;
	a->next = b;
	*swap = a;
	if (i == 1)
		write(1, "pb\n", 3);
}
