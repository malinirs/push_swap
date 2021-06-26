#include "push_swap.h"

static t_list	*selection(int *arr, t_list *list, t_size len)
{
	int		i;
	int		j;
	int		max;
	t_list	*head;

	j = 0;
	i = j + 1;
	max = arr[j];
	while (arr[i] && i < len.size_a)
	{
		if (max < arr[i])
		{
			max = arr[i];
			j = i;
		}
		i++;
	}
	i = -1;
	while (list != NULL && ++i < j)
		list = list->next;
	head = list; /** markup_head */
	return (head);
}

static int	write_Keep_A(t_list *list)
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

void	geater_than(t_list **list, t_size len)
{
	t_list	*temp;
	int		*arr;
	int		i;
	t_list	*head;

	temp = *list;
	arr = malloc(sizeof(int) * len.size_a);
	if (!arr)
		clear_list(list);
	i = 0;
	while (temp != NULL)
	{
		arr[i] = write_Keep_A(temp) + 1;
		temp = temp->next;
		i++;
	}
	arr[--i] = 1;
	head = selection(arr, *list, len);


//	i = 0;
//	while (arr[i] && i < len.size_a)
//	{
//		printf("%d ", arr[i]);
//		i++;
//	}




	free(arr);
}