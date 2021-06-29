#include "push_swap.h"

int	comparison_A(t_list *t, t_list *list)
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
	return (count);
}

t_list	*by_index(t_list **list, t_size len, int *mass)
{
	t_list	*temp;
	int		i;
	int		*max;


	temp = *list;
	i = 0;
	while (temp != NULL)
	{
		mass[i] = comparison_A(temp, *list) + 1;
		temp = temp->next;
		i++;
	}
	max = selection(mass, list, len);
	return (max);
}

void	qwe_comparison_A(t_list **t, t_list *list)
{
//		 НАПИСАТЬ ФУНКЦИЮ, КОТОРАЯ ЗАПИСЫВАЕТ 0 и 1

	t_list	*temp;
	int		i;

	temp = *t;
	i = (*t)->order + 1;
	(*t)->keep_A = 1;
	while (temp != NULL)
	{
		if (temp->order == i)
		{
			(*t)->keep_A = 1;
			i++;
		}
		else
			(*t)->keep_A = 0;
		temp = temp->next;
	}
	temp = list;
	while (temp != *t)
	{
		if (temp->order == i)
		{
			(*t)->keep_A = 1;
			i++;
		}
		else
			(*t)->keep_A = 0;
		temp = temp->next;
	}
}