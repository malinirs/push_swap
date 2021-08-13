#include "push_swap.h"

void	ra(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, tmp);
	tmp->next = NULL;
//	write(1, "ra\n", 3);

	printf("ra\n");
}

void	rb(t_list **swap)
{
	t_list	*b;

	b = *swap;
	*swap = (*swap)->next;
	ft_lstadd_back(swap, b);
	b->next = 0x0;
//	write(1, "rb\n", 3);

	printf("rb\n");
}

void	rr(t_list **list, t_list **swap)
{
	ra(list);
	rb(swap);
}

int	search_min_step(t_list **swap)
{
	t_list	*b;
	int 	min;
	int 	min_i;
	int		i;

	i = 0;
	b = *swap;
	min = b->sum_step;
	min_i = 0;
	while (b)
	{
		if (min > b->sum_step)
		{
			min = b->sum_step;
			min_i=i;
		}
		i++;
		b = b->next;
	}
	return (min_i);
}