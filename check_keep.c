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

int		search_min(t_list *list)
{
	t_list	*a;
	int 	min;
	int 	min_i;
	int		i;

	i = 0;
	a = list;
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

//int		search_max(t_list **list)
//{
//	t_list	*a;
//	int 	max;
//	int 	max_i;
//	int		i;
//
//	i = 0;
//	a = *list;
//	max = a->nbr;
//	max_i = 0;
//	while (a)
//	{
//		if (max < a->nbr)
//		{
//			max = a->nbr;
//			max_i=i;
//		}
//		i++;
//		a = a->next;
//	}
//	return (max_i);
//}

//t_list	*create_pointer_min(t_list *list)
//{
//	t_list *a;
//	int min;
//	t_list *temp;
//	int i;
//
//	a = list;
//	i = 0;
//	min = search_min(list);
//	while (min > i++)
//		a = a->next;
//	temp = a;
//	while (temp)
//		temp = temp->next;
//	temp = list;
//	if (i - 1 > 0)
//	{
//		while (i--)
//			ft_lstadd_back(&a, temp);
//		temp->next = NULL;
//	}
//	return (a);
//}

int		search_position(t_list *list, t_list *swap)
{
	int		i;
	int		min;
	t_list	*a;

	i = 0;
	a = list;
	min = search_min(list);
	while (i++ < min)
		a = a->next;
	if (a->nbr > swap->nbr)
		return (min);
	i = 0;
	while (a)
	{
		if (swap->nbr < a->nbr)
			return (i + min);
		a = a->next;
		i++;
	}
	i = 0;
	while (i < min)
	{
		if (swap->nbr < list->nbr)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}

void	check_step_A(t_list **list, t_list **swap, t_size *len)
{
	t_list	*b;
	int		position;

	b = *swap;

	while (b)
	{
		b->ra = 0;
		b->rra = 0;
		position = search_position(*list, *swap);
		if (position == len->size_a)
			position = search_min(*list);
		if (position > 0 && position <= len->size_a / 2)
			b->ra = 1;
		else if (position > len->size_a / 2)
		{
			position = len->size_a - position;
			b->rra = 1;
		}
		b->step_A = position;
		b = b->next;
	}




//	printf("\nb->step_A = %d for ", b->step_A);
//	printf("b->nbr = %d\n", b->nbr);



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

void	check_step_B(t_list **swap, t_size *len)
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
	if ((*list)->ra == 1 && (*swap)->rb == 1)
	{
		while (min->step_B-- > 0 && min->step_A-- > 0)
			rr(list, swap);
	}
	else if ((*list)->rra == 1 && (*swap)->rrb == 1)
	{
		while (min->step_B-- > 0 && min->step_A-- > 0)
			rrr(list, swap);
	}
	if ((*swap)->ra == 1)
	{
		while (min->step_A-- > 0)
			ra(list);
	}
	else if ((*swap)->rra == 1)
	{
		while (min->step_A-- > 0)
			rra(list);
	}
	if ((*swap)->rb == 1)
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
	min = search_min(*list);
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

//	t_list *a;
//	a = *list;
//	printf("\nlist: ");
//	while(a != NULL)
//	{
//		printf("%d ", a->nbr);
//		a = a->next;
//	}
//	a = *swap;
//	printf("\nswap: ");
//	while(a != NULL)
//	{
//		printf("%d ", a->nbr);
//		a = a->next;
//	}
//	printf("\n");

	while (*swap)
	{
		check_step_B(swap, len);
		check_step_A(list, swap, len);
		min = summ_step(swap);
		realize_move(list, swap, min, len);


//		a = *list;
//		printf("\nlist: ");
//		while(a != NULL)
//		{
//			printf("%d ", a->nbr);
//			a = a->next;
//		}
//		a = *swap;
//		printf("\nswap: ");
//		while(a != NULL)
//		{
//			printf("%d ", a->nbr);
//			a = a->next;
//		}
//		printf("\n");
	}
	transition_min_nbr(list, len);


//	a = *list;
//	printf("\nlist: ");
//	while(a != NULL)
//	{
//		printf("%d ", a->nbr);
//		a = a->next;
//	}
//	a = *swap;
//	printf("\nswap: ");
//	while(a != NULL)
//	{
//		printf("%d ", a->nbr);
//		a = a->next;
//	}
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



















