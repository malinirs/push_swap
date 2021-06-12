#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nbr; /** значение, которое нужно отсортировать */
//	int				order; /** порядок в котором находится это значение в уже отсортированном массиве */
//	int				count; /** флаг, который помечает,что этот элемент стека А уже был в стеке Б */
	struct s_list	*next; /** ссылка на следующий лист */
	struct s_list	*previous; /** ссылка на предыдущий лист */
}				t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int srcs);
int		ft_atoi(char *str, t_list **list);
void	ra(t_list **list);
t_list 	write_list(char **argv, t_list **list);
int		ft_isdigit(int c);
void	close_program(void);
void	sort_nbr(t_list **list);
void	ra(t_list **list);

#endif