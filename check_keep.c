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

void	check_step_A(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;
	int		i;

	b = *swap;
	while (b)
	{
		a = *list;
		i = 0;
		while (a->nbr < b->nbr && a)
		{
			i++;
			a = a->next;
		}
		if (i > len->size_a / 2)
		{
			i = len->size_a - i;
			b->rra = 1;
		}
		b->step_A = i;
		b = b->next;
	}


	printf("\nstep_A = ");
	b = *swap;
	while (b != NULL)
	{
		printf("%d ", b->step_A);
		b = b->next;
	}
	printf("\nrra = ");
	b = *swap;
	while (b != NULL)
	{
		printf("%d ", b->rra);
		b = b->next;
	}
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
		b = b->next;
	}

	printf("\nstep_B = ");
	b = *swap;
	while (b != NULL)
	{
		printf("%d ", b->step_B);
		b = b->next;
	}
	printf("\nrrb = ");
	b = *swap;
	while (b != NULL)
	{
		printf("%d ", b->rrb);
		b = b->next;
	}
}

void	check_rr(t_list **list, t_list **swap)
{
	t_list	*a;
	t_list	*b;

	a = *list;
	b = *swap;
	while (*list && *swap)
	{
		if ((*swap)->step_B > 0 && (*swap)->step_B == (*swap)->step_A && \
		(*swap)->rra == 0 && (*swap)->rrb == 0)
		{
		//	rr(list, swap);
			(*swap)->rb = 1;
			(*list)->ra = 1;
		}
		*swap = (*swap)->next;
		*list = (*list)->next;
	}
	*swap = b;
	*list = a;

	printf("\nra ");
	a = *list;
	while(a != NULL)
	{
		printf("%d ", a->ra);
		a = a->next;
	}
	printf("\nrb ");
	a = *swap;
	while(a != NULL)
	{
		printf("%d ", a->rb);
		a = a->next;
	}
}

void	check_keep_A(t_list **list, t_list **swap, t_size *len)
{
	while (check_zero(*list))
	{
		if ((*list)->keep_A == 0)
			pb(list, swap, len);
		else
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

	check_step_B(list, swap, len);
	check_step_A(list, swap, len);
	check_rr(list, swap);
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



















