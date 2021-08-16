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

int	by_index(t_list **list, t_size *len, int *mass)
{
	t_list	*temp;
	int		i;

	temp = *list;
	i = 0;

//		printf("\n mass[i] =");
	while (temp != NULL)
	{
		mass[i] = comparison_A(temp, *list) + 1;

//				printf(" %d", mass[i]);

		temp = temp->next;
		i++;
	}
	len->index = selection(mass, len);
	i = 0;
	while (mass[i] != len->index[0])
		i++;
	return (i);
}


void	keep_A_index(t_list **list, t_list *head)
{
	t_list	*temp;
	int		i;

	temp = head;
	i = temp->order + 1;
	while (temp != NULL)
	{
		if (temp->order == i)
		{
			temp->keep_A = 1;
			i++;
		}
		else
			temp->keep_A = 0;
		temp = temp->next;
	}
	temp = *list;
	while (temp != head)
	{
		if (temp->order == i)
		{
			temp->keep_A = 1;
			i++;
		}
		else
			temp->keep_A = 0;
		temp = temp->next;
	}
	temp->keep_A = 1;

//	printf("\nkeep_A_index = ");
//	temp = *list;
//	while (temp != NULL)
//	{
//		printf("%d ", temp->keep_A);
//		temp = temp->next;
//	}
}

void	keep_A_greater(t_list **list, t_size *len)
{
	t_list	*a;
	t_list	*b;

	b = *list;
	len->count = 0;
	while (len->count < len->i_greater)
	{
		len->count++;
		b = b->next;
	}
	a = b;
	b = b->next;
	while (b != NULL)
	{
		if (b->nbr > a->nbr)
		{
			a->keep_A = 1;
			a = b;
		}
		else
			a->keep_A = 0;
		b = b->next;
	}
	b = *list;
	len->count = 0;
	while (len->count++ < len->i_greater)
	{
		if (b->nbr > a->nbr)
		{
			a->keep_A = 1;
			a = b;
		}
		else
			a->keep_A = 0;
		b = b->next;
	}
	a->keep_A = 1;


//	t_list	*a;
//	t_list	*b;
//
//	a = *list;
//	while (i > 0)
//	{
//		a->keep_A = 0;
//		a = a->next;
//		i--;
//	}
//	b = a->next;
//	while (b != NULL)
//	{
//		if (b->nbr > a->nbr)
//		{
//			a->keep_A = 1;
//			a = b;
//		}
//		else
//			a->keep_A = 0;
//		b = b->next;
//	}
//	a->keep_A = 1;



//	printf("\nkeep_A_greater = ");
//	a = *list;
//	while (a != NULL)
//	{
//		printf("%d ", a->keep_A);
//		a = a->next;
//	}
}
