#include "push_swap.h"

void	rra(t_list **list)
{
	t_list	*temp;
//	t_list	*tmp;
	int		count;

	temp = *list;
	count = -1;
	while (*list != NULL && ++count < (ft_lstsize(temp) - 1))
		*list = (*list)->next;
	(*list)->next = temp;
	temp = *list;
	while (temp != NULL && 0 < count--)
		temp = temp->next;
	temp->next = NULL;
/**  писать выполнение команды во время вызова, а не в самой функции, чтобы
 * при выполнении rrr напечатать только rrr, а не rra и rrb */

//	write(1, "rra\n", 4);
	printf("rra\n");
//	tmp = *list;
//	while(tmp != NULL)
//	{
//		printf("%d ", tmp->nbr);
//		tmp = tmp->next;
//	}
}

void	rrb(t_list **swap)
{
	t_list	*b;
	int		count;
	int		i;

	b = *swap;
	while(b != NULL)
	{
		printf("%d ", b->nbr);
		b = b->next;
	}

	b = *swap;
	i = -1;
	count = ft_lstsize(b) - 1;
	while (*swap != NULL && count > ++i)
		*swap = (*swap)->next;
	(*swap)->next = b;
	b = *swap;
	while (b != NULL && count-- > 0)
		b = b->next;
	b->next = NULL;

	//write(1, "rrb\n", 4);
	printf("rrb\n");
//	b = *swap;
//	while(b != NULL)
//	{
//		printf("%d ", b->nbr);
//		b = b->next;
//	}
}

void	rrr(t_list **list, t_list **swap)
{
	rra(list);
	rrb(swap);
}
