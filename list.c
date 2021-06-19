#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_lst;

	if (!(*lst))
		*lst = new;
	new_lst = *lst;
	while (new_lst->next_A != NULL)
		new_lst = new_lst->next_A;
	new_lst->next_A = new;
	new->next_A = NULL;
}

t_list	*ft_lstnew(int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0x0);
	new->nbr = nbr;
	new->next_A = NULL;
	return (new);
}

void	free_list(t_list **list)
{
	t_list	*temp;

	while (*list != NULL)
	{
		temp = (*list)->next_A;
		free(*list);
		*list = temp;
	}
}

void	clear_list(t_list **list)
{
	free_list(list);
	close_program();
}

int	ft_lstsize(t_list	*lst)
{
	int		i;
	t_list	*new_lst;

	if (!lst)
		return (0);
	i = 0;
	new_lst = lst;
	while (new_lst != NULL)
	{
		new_lst = new_lst->next_A;
		i++;
	}
	return (i);
}