/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_contin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:14:46 by awoods            #+#    #+#             */
/*   Updated: 2021/08/18 15:14:48 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_str2(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) > 0)
	{
		i++;
		flag++;
	}
	if (!str[i] && flag)
		flag = 1;
	else
		flag = 0;
	return (flag);
}

int	sort(t_list *A, t_list *B)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = A;
	while (temp->next)
	{
		if (temp->nbr < temp->next->nbr)
			count++;
		temp = temp->next;
	}
	if (count + 1 == ft_lstsize(A) && B == NULL)
		return (1);
	return (0);
}

static void	check_contin(char *line)
{
	free(line);
	write(1, "Error\n", 6);
	exit(0);
}

static int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	check(t_list **A, t_list **B, char *line, t_size *len)
{
	if (ft_strncmp(line, "sa\n", 2) == 0)
		sa_mod(A, len);
	else if (ft_strncmp(line, "sb\n", 2) == 0)
		sb_mod(B, len);
	else if (ft_strncmp(line, "ss\n", 2) == 0)
		ss_mod(A, B, len);
	else if (ft_strncmp(line, "pb\n", 2) == 0)
		pb_mod(A, B, len);
	else if (ft_strncmp(line, "pa\n", 2) == 0)
		pa_mod(A, B, len);
	else if (ft_strncmp(line, "rrr\n", 3) == 0)
		rrr_mod(A, B, len);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		rra_mod(A, len);
	else if (ft_strncmp(line, "rrb\n", 3) == 0)
		rrb_mod(B, len);
	else if (ft_strncmp(line, "rr\n", 2) == 0)
		rr_mod(A, B, len);
	else if (ft_strncmp(line, "ra\n", 2) == 0)
		ra_mod(A, len);
	else if (ft_strncmp(line, "rb\n", 2) == 0)
		rb_mod(B, len);
	else
		check_contin(line);
}
