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
//	int		*max;

	temp = *list;
	i = 0;

//	printf("\n arr[i] =");
	while (temp != NULL)
	{
		arr[i] = comparison_Keep_A(temp) + 1;

//		printf(" %d", arr[i]);

		temp = temp->next;
		i++;
	}
	arr[--i] = 1;
	len->greater = selection(arr, len);
	i = 0;
	while (arr[i] != len->greater[0])
		i++;
	return (i);
//	return(max_greater);
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

//	printf("arr = %d,  mass = %d", arr[len->greater_a], mass[len->index_a]);



	if (arr[len->i_greater] > mass[len->i_index])
		keep_A_greater(list, len->i_greater);
	else
	{
		while (i++ < len->i_index)
			temp = temp->next;
		keep_A_index(list, temp);
	}
	free(arr);
	free(mass);
}