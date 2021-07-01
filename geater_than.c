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
	int		*head;

	j = 0;
	i = j + 1;
	max = arr[j];
	while (arr[i] && i < len->size_a)
	{
		if (max < arr[i])
		{
			max = arr[i];
			j = i;
		}
		i++;
	}
	head = arr;
	return (&head[j]);
}

int	comparison_Keep_A(t_list *list)
{
	int		count;
	t_list	*a;
	t_list	*b;

	a = list;
	b = a->next;
	count = 0;
	while (b != NULL)
	{
		if (b->nbr > a->nbr)
		{
			count++;
			a = b;
		}
		b = b->next;
	}
	return (count);
}

static int	greater_than(t_list **list, t_size *len, int *arr)
{
	t_list	*temp;
	int		i;
	int		*max;

	temp = *list;
	i = 0;
	while (temp != NULL)
	{
		arr[i] = comparison_Keep_A(temp) + 1;
		temp = temp->next;
		i++;
	}
	arr[--i] = 1;
	max = selection(arr, len);
	i = 0;
	while (arr[i] != *max)
		i++;
	return (i);
}

void	markup_mode(t_list **list, t_size *len)
{
	int		*arr;
	int		*mass;
	t_list	*temp;

	arr = malloc(sizeof(int) * len->size_a);
	if (!arr)
	{
		arr = NULL;
		clear_list(list);
	}
	len->greater_a = greater_than(list, len, arr) + 1;

	printf("greater index = %d\n", len->greater_a);

	mass = malloc(sizeof(int) * len->size_a);
	if (!mass)
	{
		mass = NULL;
		clear_list(list);
	}
	len->index_a = by_index(list, len, mass);

	printf("index index = %d\n", len->index_a);


	int i = 0;
	temp = *list;
	if (arr[len->greater_a] > mass[len->index_a])
		keep_A_greater(list, len->greater_a);
	else
	{
		while (i++ < len->index_a)
			temp = temp->next;
		keep_A_index(list, temp);
	}


	free(arr);
	free(mass);
}