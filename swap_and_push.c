#include "push_swap.h"

void	sa(t_list **list)
{
//	t_list	*a;
	t_list	*t;

	t_list *a;
	t_list *b;
	t_list *c;

	a = *list;
	b = a->next;
	c = b->next; // c = a->next->next;
	*list = b;
	b->next = a;
	a->next = c;

//	a = *list; /** a->b->c */
//	*list = (*list)->next; /** *list: b->c, первый эл-т это b */
//	a->next = (*list)->next; /** a->c, ссылка 1 эл-та = 3 эл-ту*/
//	(*list)->next = a; /** b->a, итого b->a->c */


	write(1, "sa\n", 3);
	t = *list;
	printf("list sa: ");
	while(t != NULL)
	{
		printf("%d ", t->nbr);
		t = t->next;
	}
}

void	sb(t_list **swap)
{
	t_list	*b;
	t_list	*t;

	b = *swap;
	*swap = (*swap)->next;
	b->next = (*swap)->next;
	(*swap)->next = b;

	write(1, "sb\n", 3);
	t = *swap;
	printf("\n");
	while(t != NULL)
	{
		printf("%d ", t->nbr);
		t = t->next;
	}
}

void	ss(t_list **list, t_list **swap)
{
	sa(list);
	sb(swap);
}

void	pa(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = *list;
	b = *swap;
	*swap = (*swap)->next;
	b->next = a;
	*list = b;
	write(1, "pa\n", 3);
	len->size_a++;
	len->size_b--;

	tmp = *list;
	printf("list: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
	tmp = *swap;
	printf("\nswap: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next;
	}
}

void	pb(t_list **list, t_list **swap, t_size *len)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = *list;
	b = *swap;
	*list = (*list)->next;
	a->next = b;
	*swap = a;
//	write(1, "pb\n", 3);
	len->size_a--;
	len->size_b++;


//	tmp = *list;
//	printf("list pb: ");
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}
//	tmp = *swap;
//	printf("\nswap pb: ");
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}
}
