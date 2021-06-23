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
	printf("\n");
	while(tmp != NULL)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->next_A;
	}
}

void	sort_nbr(t_list **list)
{
//	sa(list);
//	ra(list);
	rra(list);
}