#include "push_swap.h"

//void	write_Keep_A(t_list **list, t_list *head)
//{
//	t_list	*temp;
//
//	temp = *list;
//	while (temp != head)
//	{
//		temp->keep_A = 0;
//		temp = temp->next;
//	}
//	if (temp->nbr == head->nbr)
//		temp->keep_A = 1;
//	temp = temp->next;
//	while (temp != NULL)
//	{
//		if (head->nbr < temp->nbr)
//		{
//			temp->keep_A = 1;
//			head = temp;
//		}
//		temp = temp->next;
//	}
//
//	printf("\nKeep_A = ");
//	temp = *list;
//	while (temp != NULL)
//	{
//		printf("%d ", temp->keep_A);
//		temp = temp->next;
//	}
//}

int	*selection(int *arr, t_size *len)
{
	int		i;
	int		j;
	int		max;

	j = 0;
	i = j + 1;
	max = arr[j];
	while (arr[i] && i < len->size_a)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			j = i;
		}
		i++;
	}
	return (&arr[j]);
}

void	comparison_Keep_A(t_list *list, t_size *len)
{
//	int		count;
//	t_list	*a;
//	t_list	*b;
//
//	a = list;
//	b = a->next;
//	count = 0;
//	while (b != NULL)
//	{
//		if (b->nbr > a->nbr)
//		{
//			count++;
//			a = b;
//		}
//		b = b->next;
//	}
//	return (count);



	t_list	*a;
	t_list	*b;

	len->i_2 = 0;
	a = list;
	while (a)
	{
		len->count = 0;
		len->i = 0;
		b = a;
		len->value = b->nbr;
		while (len->size_a > len->i)
		{
			if (b->nbr > len->value)
			{
				len->value = b->nbr;
				len->count++;
			}
			b = b->next;
			if (b == 0x0)
				b = list;
			len->i++;
		}
		a->ind_greater = len->count;

//		printf(" %d", arr[len->i_2] );

		a = a->next;
	}




//	int		i;
//
//	i = 0;
//	count = 0;
//	a = t;
//	b = t->next;
//	while (b && i < len->size_a)
//	{
//		if (b->nbr > t->nbr)
//		{
//			count++;
//			t = b;
//		}
//		b = b->next;
//		i++;
//	}
//	t = list;
//	b = list->next;
//	while ((b && t != a) && i < len->size_a)//b && b != a && t != a)
//	{
//		if (b->nbr > t->nbr)
//		{
//			count++;
//			t = b;
//		}
//		b = b->next;
//		i++;
//	}

//	return (count);
}

static int	greater_than(t_list **list, t_size *len, int *arr)
{
	t_list	*temp;
	int		i;


	comparison_Keep_A(*list, len);

//	printf("arr[i] = ");

	i = 0;
	temp = *list;
	while (temp)
	{
		arr[i] = temp->ind_greater + 1;
//		printf(" %d", arr[i]);
		temp = temp->next;
		i++;
	}

	len->greater = selection(arr, len);
	i = 0;
	while (arr[i] != len->greater[0])
		i++;
	return (i);



//	t_list	*temp;
//	int		i;
//
//
//	temp = *list;
//	i = 0;
//
//	printf("\n arr[i] =");
//	while (temp != NULL)
//	{
//		arr[i] = comparison_Keep_A(*list, len) + 1;
//
//		printf(" %d", arr[i]);
//
//		temp = temp->next;
//		i++;
//	}
//	arr[--i] = 1;
//	len->greater = selection(arr, len);
//	i = 0;
//	while (arr[i] != len->greater[0])
//		i++;
//	return (i);
}


void	check_stack_A_5(t_list **list)
{
	if ((*list)->nbr > (*list)->next->nbr && \
	(*list)->next->nbr > (*list)->next->next->nbr && \
	(*list)->next->next->nbr > (*list)->next->next->next->nbr && \
	(*list)->next->next->next->nbr > (*list)->next->next->next->next->nbr)
	{
		ra(list, 1);
		sa(list);
		rra(list, 1);
		sa(list);
		ra(list, 1);
		sa(list);
		ra(list, 1);
		ra(list, 1);
		sa(list);
		exit(0);
	}
}

void	check_stack_A_3(t_list **list)
{
	int a;
	int b;
	int c;

	a = (*list)->nbr;
	b = (*list)->next->nbr;
	c = (*list)->next->next->nbr;
	if (a < b && a < c && b > c && c > a)
	{
		sa(list);
		ra(list, 1);
	}
	else if (a > b && b > c && a > c)
	{
		ra(list, 1);
		sa(list);
	}
	else if (a > b && b < c && a > c)
		ra(list, 1);
	else if (a > b && b < c && a < c)
		sa(list);
	else if (c < b && b > a)
		rra(list, 1);
	exit(0);
}

void	markup_mode(t_list **list, t_list **swap, t_size *len)
{
	int		*arr;
	int		*mass;
	t_list	*temp;

	if (len->size_a == 5)
		check_stack_A_5(list);
	if (len->size_a == 3)
		check_stack_A_3(list);


	arr = malloc(sizeof(int) * len->size_a);
	if (!arr)
	{
		arr = NULL;
		clear_list(list);
	}
	len->i_greater = greater_than(list, len, arr);
	mass = malloc(sizeof(int) * len->size_a);
	if (!mass)
	{
		mass = NULL;
		clear_list(list);
	}
	len->i_index = by_index(list, len, mass);

	int i = 0;
	temp = *list;
	if (arr[len->i_greater] > mass[len->i_index])
		keep_A_greater(list, len);
	else
	{
		while (i++ < len->i_index)
			temp = temp->next;
		keep_A_index(list, temp);
	}
	free(arr);
	free(mass);
}