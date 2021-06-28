#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nbr; /** значение, которое нужно отсортировать */
	int				order; /** порядок, в котором находится это значение в уже отсортированном массиве */
	int				keep_A; /** хранить ли элемент в стеке А? */
	struct s_list	*next; /** ссылка на следующий лист */
}				t_list;

typedef struct s_size
{
	int				size_a;
	int				size_b;
}				t_size;

void	close_program(void);
int		ft_isdigit_mod(int c);
int		ft_atoi_mod(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int nbr);
void	rules_swap(t_list **list);
void 	write_list(char **argv, t_list **list);
int		ft_strlen(char *str);
void	clear_list(t_list **list);
void	free_list(t_list **lst);
int		ft_lstsize(t_list	*lst);
int		ft_strchr_mod(const char *s, int c);
char	**ft_split(char const *s, char c);
void	sa(t_list **list);
void	sb(t_list **swap);
void	ss(t_list **list, t_list **swap);
void	pa(t_list **list, t_list **swap, t_size *len);
void	pb(t_list **list, t_list **swap, t_size *len);
void	ra(t_list **list);
void	rb(t_list **swap);
void	rr(t_list **list, t_list **swap);
void	rra(t_list **list);
void	rrb(t_list **swap);
void	rrr(t_list **list, t_list **swap);
void	markup_mode(t_list **list, t_size len);
t_list	*geater_than(t_list **list, t_size len);
int		comparison_Keep_A(t_list *list);
void	write_Keep_A_geater_than(t_list **list, t_list *head_geater_than);
t_list	*by_index(t_list **list, t_size len);

#endif