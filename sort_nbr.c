#include "push_swap.h"

void	sa(t_list **list)
{
	t_list	*temp;
	t_list	*t;

	temp = *list; /** a->b->c */
	*list = (*list)->next_A; /** *list: b->c, первый эл-т это b */
	temp->next_A = (*list)->next_A; /** a->c, ссылка 1 эл-та = 3 эл-ту*/
	(*list)->next_A = temp; /** b->a, итого b->a->c */


	write(1, "sa\n", 3);
	t = *list;
	printf("\n");
	while(t != NULL)
	{
		printf("%d ", t->nbr);
		t = t->next_A;
	}
}

void	pa(t_list **list, t_list **push)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = *list;
	b = *push;
	*push = (*push)->next_B;
	b->next_B = a;
	*list = b;

//	*list = (*list)->next_A;
//	a->next_A = b;
//	*push = a;

//	write(1, "\n\n", 2);
	write(1, "pa\n", 3);
	tmp = *list;
	printf("\nlist: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next_A;
	}
	tmp = *push;
	printf("\npush: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next_A;
	}
}

void	pb(t_list **list, t_list **push)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	a = *list;
	b = *push;
	*list = (*list)->next_A;
	a->next_A = b;
	*push = a;

	write(1, "pb", 2);
	tmp = *list;
	printf("\nlist: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next_A;
	}
	tmp = *push;
	printf("\npush: ");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next_A;
	}
}

void	ra(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next_A; /** a[i] = a[i + 1] */
	ft_lstadd_back(list, tmp);
	tmp->next_A = NULL;


	write(1, "ra\n", 3);
	tmp = *list;
	printf("\n");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next_A;
	}
}

void	rra(t_list **list)
{
	t_list	*temp;
	t_list	*tmp;
	int		count;

	temp = *list;
	count = -1;
	while (*list != NULL && ++count < (ft_lstsize(temp) - 1))
		*list = (*list)->next_A;
	(*list)->next_A = temp;
	temp = *list;
	while (temp != NULL && 0 < count--)
		temp = temp->next_A;
	temp->next_A = NULL;


	write(1, "rra\n", 4);
	tmp = *list;
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next_A;
	}
}

void	sort_nbr(t_list **list)
{
	t_list	*push;
	t_list	*tmp;

//	sa(list);
//	pb(list, &push);
	pb(list, &push);
	pa(list, &push);
//	pb(list, &push);
//	ra(list);
//	rra(list);

//	tmp = *list;
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next_A;
//	}

	free_list(list);
//	free_list(&push);
}