#include "push_swap.h"

static int	comparison_A(t_list *temp)
{
	t_list	*head;
	t_list	*first;

	first = temp;
	head = temp;
	while (head != NULL || temp->order != 0)
		head = head->next;
	printf("temp->order = %d", temp->order);
}

t_list	*by_index(t_list **list, t_size len)
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
		arr[i] = comparison_A(temp) + 1;
		temp = temp->next;
		i++;
	}
	arr[--i] = 1;
//	head = selection(arr, *list, len);
	free(arr);
	return (head);
}