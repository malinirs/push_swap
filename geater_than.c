#include "push_swap.h"

void	write_Keep_A(t_list **list, t_list *head)
{
	t_list	*temp;

	temp = *list;
	while (temp != head)
	{
		temp->keep_A = 0;
		temp = temp->next;
	}
	if (temp->nbr == head->nbr)
		temp->keep_A = 1;
	temp = temp->next;
	while (temp != NULL)
	{
		if (head->nbr < temp->nbr)
		{
			temp->keep_A = 1;
			head = temp;
		}
		temp = temp->next;
	}

	printf("\nKeep_A = ");
	temp = *list;
	while (temp != NULL)
	{
		printf("%d ", temp->keep_A);
		temp = temp->next;
	}
}

int	*selection(int *arr, t_list **list, t_size len)
{
	int		i;
	int		j;
	int		max;
//	t_list	*head;
	int		*head;

	j = 0;
	i = j + 1;
	max = arr[j];
//	temp = arr;
	while (arr[i] && i < len.size_a)
	{
		if (max < arr[i])
		{
			max = arr[i];
			j = i;
		}
		i++;
	}
//	i = -1;
//	head = *list; /** markup_head */
//	while (head != NULL && ++i < j)
//		head = head->next;
//	head = list; /** markup_head */
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
	while (b != NULL || a != NULL)
	{
		while (b != NULL)
		{
			if (b->nbr > a->nbr)
			{
				count++;
				break;
			}
			b = b->next;
		}
		if (b == NULL)
			break;
		a = b;
		b = b->next;
	}
	return (count);
}

static int	*greater_than(t_list **list, t_size len, int *arr)
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
	max = selection(arr, list, len);
	return (max);
}

void	markup_mode(t_list **list, t_size len)
{
	int		*greater;
	int		*index;
	int		*arr;
	int		*mass;
	t_list	*temp;

	arr = malloc(sizeof(int) * len.size_a);
	if (!arr)
	{
		arr = NULL;
		clear_list(list);
	}

	greater = greater_than(list, len, arr);

	printf("greater nbr = %d\n", *greater);

	mass = malloc(sizeof(int) * len.size_a);
	if (!mass)
	{
		mass = NULL;
		clear_list(list);
	}
	index = by_index(list, len, mass);

	printf("\n");
	printf("index nbr = %d\n", *index);

	int i = 0;
	temp = *list;
	if (*greater > *index)
	{
//		while ()
		write_Keep_A(list, greater);
	}
	else
	{
		while (mass[i] != *index)
		{
			i++;
			temp = temp->next;
		}
		qwe_comparison_A(list, temp);
	}



	free(arr);
	free(mass);
}