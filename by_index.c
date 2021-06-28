#include "push_swap.h"

static int	comparison_A(t_list *t, t_list *list)
{
	int		count;
	t_list	*temp;
	int		i;

	count = 0;
	temp = t;
	i = t->order + 1;
	while (temp != NULL)
	{
		if (temp->order == i)
		{
			count++;
			i++;
		}
		temp = temp->next;
	}
	temp = list;
	while (temp != t)
	{
		if (temp->order == i)
		{
			count++;
			i++;
		}
		temp = temp->next;
	}
//	t->next = list;
//	while (t != temp)
//	{
//		count++;
//		t = t->next;
//	}

	return (count);
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
//	while (temp != NULL)
//		temp = temp->next;
//	temp->next = *list;
	i = 0;
	while (temp != NULL)
	{
		arr[i] = comparison_A(temp, *list) + 1;
//		t = t->next;
		temp = temp->next;
//		printf("%d ", arr[i]);
		i++;
	}
//	arr[--i] = 1;

	printf("\narr =");
	i = 0;
	while (i <  len.size_a)
	{
		printf("% d", arr[i]);
		i++;
	}




//	head = selection(arr, *list, len);
	free(arr);
	return (head);
}