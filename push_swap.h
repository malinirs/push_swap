#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int nbr; /** значение, которое нужно отсортировать */
//	int				order; /** порядок в котором находится это значение в уже отсортированном массиве */
//	int				count; /** флаг, который помечает,что этот элемент стека А уже был в стеке Б */
	struct s_list *next; /** ссылка на следующий лист */
//	struct s_list *previous; /** ссылка на предыдущий лист */
}				t_list;

void	close_program(void);
int		ft_isdigit_mod(int c);
int		ft_atoi_mod(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int nbr);
void	ra(t_list **list);
void	sort_nbr(t_list **list);
t_list 	write_list(char **argv, t_list **list);
int		ft_strlen(char *str);
void	clear_list(t_list **list);
void	free_list(t_list **lst);
int		ft_lstsize(t_list	*lst);

#endif