/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:49:42 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 14:49:46 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nbr;
	int				order;
	int				keep_A;
	int				step_A;
	int				step_B;
	int				rra;
	int				rrb;
	int				ra;
	int				rb;
	int				sum_step;
	int				ind_greater;
	struct s_list	*next;
}				t_list;

typedef struct s_size
{
	int				size_a;
	int				size_b;
	int				i_index;
	int				i_greater;

	int				*index;
	int				*greater;

	int				count;
	int				i;
	int				value;
	int				min;
}				t_size;

int		by_index(t_list **list, t_size *len, int *mass);
void	keep_A_index(t_list **list, t_list *head);
void	keep_A_greater(t_list **list, t_size *len);
void	check_keep_A(t_list **list, t_list **swap, t_size *len);
void	check_step_A(t_list **list, t_list **swap, t_size *len);
void	check_step_B(t_list **swap, t_size *len);
t_list	*summ_step(t_list **swap);
int		search_min(t_list *list);
void	transition_min_nbr(t_list **list, t_size *len);
void	realize_move(t_list **list, t_list **swap, t_list *min);
void	markup_mode(t_list **list, t_size *len);
void	check_stack_A_5(t_list **list);
void	check_stack_A_3(t_list **list);
int		greater_than(t_list **list, t_size *len, int *arr);
int		*selection(int *arr, t_size *len);
void	check_duplicat(t_list **list);
void	rra(t_list **list, int i);
void	rrb(t_list **swap, int t);
void	rrr(t_list **list, t_list **swap);
void	ra(t_list **list, int i);
void	rb(t_list **swap, int i);
void	rr(t_list **list, t_list **swap);
char	**ft_split(char const *s, char c);
void	rules_swap(t_list **list);
void	sa(t_list **list);
void	sb(t_list **swap);
void	ss(t_list **list, t_list **swap);
void	pa(t_list **list, t_list **swap, t_size *len);
void	pb(t_list **list, t_list **swap, t_size *len);
void	clear_list(t_list **list);
void	free_list(t_list **lst);
void	close_program(void);
int		ft_strchr_mod(const char *s, int c);
long	ft_atoi_mod(char *str);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int nbr);
int		ft_lstsize(t_list	*lst);
void	check_sort(t_list **list, t_size *len);

void	sa_mod(t_list **list, t_size *len);
void	sb_mod(t_list **swap, t_size *len);
void	ss_mod(t_list **list, t_list **swap, t_size *len);
void	pa_mod(t_list **list, t_list **swap, t_size *len);
void	pb_mod(t_list **list, t_list **swap, t_size *len);
void	rr_mod(t_list **list, t_list **swap, t_size *len);
void	rrr_mod(t_list **list, t_list **swap, t_size *len);
void	rra_mod(t_list **list, t_size *len);
void	rrb_mod(t_list **swap, t_size *len);
void	ra_mod(t_list **list, t_size *len);
void	rb_mod(t_list **swap, t_size *len);
int		sort(t_list *A, t_list *B);
void	check(t_list **A, t_list **B, char *line, t_size *len);
int		check_str2(char *str);

#endif