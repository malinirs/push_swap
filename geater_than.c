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

t_list	*geater_than(t_list **list, t_size len)
{
	t_list	*temp;
	int		*arr;
	int		i;
	t_list	*head;

	temp = *list;
	arr = malloc(sizeof(int) * len.size_a);
	if (!arr)
	{
		arr = NULL;
		clear_list(list);
	}
	i = 0;
	while (temp != NULL)
	{
		arr[i] = comparison_Keep_A(temp) + 1;
		temp = temp->next;
		i++;
	}
	arr[--i] = 1;
	head = selection(arr, *list, len);
	free(arr);
	return (head);
}

void	write_Keep_A_geater_than(t_list **list, t_list *head_geater_than)
{
	t_list	*temp;

	temp = *list;
	while (temp != head_geater_than)
	{
		temp->keep_A_geater = 0;
		temp = temp->next;
	}
	if (temp->nbr == head_geater_than->nbr)
		temp->keep_A_geater = 1;
	temp = temp->next;
	while (temp != NULL)
	{
		if (head_geater_than->nbr < temp->nbr)
		{
			temp->keep_A_geater = 1;
			head_geater_than = temp;
		}
		temp = temp->next;
	}

//	temp = *list;
//	while (temp != NULL)
//	{
//		printf("%d ", temp->keep_A_geater);
//		temp = temp->next;
//	}
}

void	markup_mode(t_list **list, t_size len)
{
	t_list	*head_geater_than;
	t_list	*head_by_index;

	head_geater_than = geater_than(list, len);
//	printf("nbr = %d\n", head_geater_than->nbr);
//	printf("order = %d\n", head_geater_than->order);
	write_Keep_A_geater_than(list, head_geater_than);

//	head_by_index = by_index(list, len);

}