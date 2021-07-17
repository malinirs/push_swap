#include "push_swap.h"

static int	check_zero(t_list *list)
{
	while (list != NULL)
	{
		if (list->keep_A == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

int		search_min(t_list **list)
{
	t_list	*a;
	int 	min;
	int 	min_i;
	int		i;

	i = 0;
	a = *list;
	min = a->nbr;
	min_i = 0;
	while (a)
	{
		if (min > a->nbr)
		{
			min = a->nbr;
			min_i=i;
		}
		i++;
		a = a->next;
	}
	return (min_i);
}

int		search_max(t_list **list)
{
	t_list	*a;
	int 	max;
	int 	max_i;
	int		i;

	i = 0;
	a = *list;
	max = a->nbr;
	max_i = 0;
	while (a)
	{
		if (max < a->nbr)
		{
			max = a->nbr;
			max_i=i;
		}
		i++;
		a = a->next;
	}
	return (max_i);
}

void	check_step_A(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		ip;

	b = *swap;
	while (b)
	{
		a = *list;
		i = 1;
		ip = -1;
		while (a)
		{
			if (b->nbr > a->nbr)
				ip = i;
			else
				break;
			i++;
			a = a->next;
		}
		b->rra = 0;
		if (ip - 1 == len->size_a)
		{
			ip = search_max(list);
			if (ip > len->size_a / 2)
			{
				ip = len->size_a - ip;
				b->rra = 1;
			}
//			else
//				b->rra = 0;
		}
		else if (ip > len->size_a / 2)
		{
			ip = len->size_a - ip;
			b->rra = 1;
		}
		else if (ip < 0)
		{
			ip = search_min(list);
			if (ip > len->size_a / 2)
			{
				ip = len->size_a - ip;
				b->rra = 1;
			}
		}
		b->step_A = ip;
		b = b->next;
	}


//	printf("\nstep_A = ");
//	b = *swap;
//	while (b != NULL)
//	{
//		printf("%d ", b->step_A);
//		b = b->next;
//	}
//	printf("\nrra = ");
//	b = *swap;
//	while (b != NULL)
//	{
//		printf("%d ", b->rra);
//		b = b->next;
//	}
}

void	check_step_B(t_list **list, t_list **swap, t_size *len)
{
	t_list	*b;
	int		i;

	i = 0;
	b = *swap;
	while (i <= (len->size_b / 2))
	{
		b->step_B = i;
		b = b->next;
		i++;
	}
	while (b)
	{
		b->step_B = len->size_b - i;
		i++;
		if (i > len->size_b / 2 + 1)
			b->rrb = 1;
		else
			b->rrb = 0;
		b = b->next;
	}





//	printf("\nstep_B = ");
//	b = *swap;
//	while (b != NULL)
//	{
//		printf("%d ", b->step_B);
//		b = b->next;
//	}
//	printf("\nrrb = ");
//	b = *swap;
//	while (b != NULL)
//	{
//		printf("%d ", b->rrb);
//		b = b->next;
//	}
}

t_list	*summ_step(t_list **swap)
{
	t_list	*b;
	t_list	*min;

	b = *swap;
	while (b)
	{
		b->sum_step = b->step_A + b->step_B;
		b = b->next;
	}
	b = *swap;
	min = b;
	while (b->next)
	{
		if (b->sum_step < b->next->sum_step)
			min = b;
		b = b->next;
	}
  	return (min);
}

void	realize_move(t_list **list, t_list **swap, t_list *min, t_size *len)
{
	if ((*list)->rra == 0 && (*swap)->rrb == 0)
	{
		while (min->step_B-- > 0 && min->step_A-- > 0)
			rr(list, swap);
	}
	else if ((*list)->rra == 1 && (*swap)->rrb == 1)
	{
		while (min->step_B-- > 0 && min->step_A-- > 0)
			rrr(list, swap);
	}
	if ((*swap)->rra == 0)
	{
		while (min->step_A-- > 0)
			ra(list);
	}
	else if ((*swap)->rra == 1)
	{
		while (min->step_A-- > 0)
			rra(list);
	}
	if ((*swap)->rrb == 0)
	{
		while (min->step_B-- > 0)
			rb(swap);
	}
	else if ((*list)->rrb == 1)
	{
		while (min->step_B-- > 0)
			rrb(swap);
	}
	pa(list, swap, len);
}

void	transition_min_nbr(t_list **list, t_size *len)
{
	t_list	*a;
	int		i;
	int		min;

	a = *list;
	i = 0;
	min = search_min(list);
	while (i++ < min)
		a = a->next;
	if (--i > len->size_a / 2)
	{
		i = len->size_a - i;
		while (i-- > 0)
			rra(list);
	}
	else
		while (i-- > 0)
			ra(list);
}

void	check_keep_A(t_list **list, t_list **swap, t_size *len)
{
	t_list	*min;

	while (check_zero(*list))
	{
		if ((*list)->keep_A == 0)
			pb(list, swap, len);
		else
			ra(list);
	}
	while (*swap)
	{
		check_step_B(list, swap, len);
		check_step_A(list, swap, len);
		min = summ_step(swap);
		realize_move(list, swap, min, len);
	}
	transition_min_nbr(list, len);


	t_list *a;
	a = *list;
	printf("\nlist: ");
	while(a != NULL)
	{
		printf("%d ", a->nbr);
		a = a->next;
	}
	a = *swap;
	printf("\nswap: ");
	while(a != NULL)
	{
		printf("%d ", a->nbr);
		a = a->next;
	}
}


//void	check_step(t_list **list, t_size *len)
//{
//	int j;
//	int n;
//	t_list	*temp;
//
//	j = 1;
//	n = len->size_a;
//	temp = *list;
//	while (n / 10 + 1 > j)
//	{
//		while (temp)
//		{
//			markup_mode(list, &len, j)
//			temp = temp->next;
//		}
//		j++;
//		temp = *list;
//	}
//}



















