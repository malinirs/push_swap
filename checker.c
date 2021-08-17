/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:42:22 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 17:42:25 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_str_list(char **str, t_list **A, t_list **B)
{
	int	j;

	j = 0;
	if (str[j])
	{
		while(str[j])
		{
			free(str[j]);
			j++;
		}
		free(str);
	}
	if (A)
		free_list(A);
	if (B)
		free_list(B);
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
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

static void	check(t_list **A, t_list **B, char *line, char **str)
{

	if (ft_strncmp(line, "sa\n", 2) == 0)
		sa_mod(A, 0);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		rra(A, 0);
	else if (ft_strncmp(line, "ra\n", 2) == 0)
		ra(A, 0);
	else if (ft_strncmp(line, "pb\n", 2) == 0)
		pb_mod(A, B, 0);
	else if (ft_strncmp(line, "sb\n", 2) == 0)
		sb_mod(B, 0);
	else if (ft_strncmp(line, "ss\n", 2) == 0)
		ss_mod(A, B);
	else if (ft_strncmp(line, "pa\n", 2) == 0)
		pa_mod(A, B, 0);
	else if (ft_strncmp(line, "rb\n", 2) == 0)
		rb(B, 0);
	else if (ft_strncmp(line, "rrb\n", 3) == 0)
		rrb(B, 0);
	else if (ft_strncmp(line, "rr\n", 2) == 0)
		rr_mod(A, B);
	else if (ft_strncmp(line, "rrr\n", 3) == 0)
		rrr_mod(A, B);
	else
	{
		free(line);
		exit (-1);
		clear_str_list(str, A, B);
	}
}

static int	check_str(char *str)
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


static void	write_list(char **str, t_list **A)
{
	char	**ptr;
	t_list	*temp;
	int		flag;
	int		number;

	ptr = str;
	while (*ptr)
	{
		flag = check_str(*ptr);
		if (!flag)
			clear_list(A);
		number = ft_atoi_mod(*ptr);
		if (number > 2147483647 || number < -2147483648)
			clear_list(A);
		temp = ft_lstnew(number);
		if (!temp)
			clear_list(A);
		ft_lstadd_back(A, temp);
		ptr++;
	}
}

int	get_next_line_mod(char **line)
{
	char	buf[10000];
	int		byte;
	int		i;

	i = 0;
	if ((read(0, &buf[i], 0) < 0) || !(line))
		return (-1);
	byte = read(0, &buf[i], 1);
	while (byte > 0 && buf[i] != '\n')
		byte = read(0, &buf[++i], 1);
	buf[i] = '\0';
	if (byte != -1)
	{
		*line = malloc(sizeof(char) * i);
		if (*line)
		{
			i = -1;
			while (buf[++i])
				(*line)[i] = buf[i];
			(*line)[i] = '\0';
		}
	}
	if (byte > 0)
		return (1);
	return (byte);

//	int		byte_was_read;
//	char	*buffer;
//	int		i;
//
//	i = 0;
//	buffer = malloc(sizeof(char) * 1024);
//	if (!buffer)
//		return (-1);
//	if (!line || read(0, &buffer[i], 0) < 0)
//		return (-1);
//	byte_was_read = read(0, &buffer[i], 1);
//	while (byte_was_read > 0 && buffer[i] != '\n')
//	{
//		byte_was_read = read(0, &buffer[i], 1);
//		i++;
//	}
//	buffer[i] = '\n';
//	if (byte_was_read < 0)
//		return (-1);
//	if (byte_was_read > 0)
//		return (1);
//	return (byte_was_read);
}

void	read_argv(t_list **A, t_list **B, char **str)
{
	char	*line;

	line = NULL;

	while (get_next_line_mod(&line))
	{
		check(A, B, line, str);
		free(line);
		line = 0x0;
	}
	if (line)
	{
		free(line);
		line = 0x0;
	}
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
//	printf("count = %d\n", count);
//	while (A)
//	{
//		printf(" %d ", A->nbr);
//		A = A->next;
//	}
	if (count + 1 == ft_lstsize(A) && B == NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**str;
	t_list	*A;
	t_list	*B;

	if (argc < 2)
		exit(0);
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	if (argc > 2)
		str = argv + 1;
	A = NULL;
	write_list(str, &A);
	B = NULL;
	read_argv(&A, &B, str);
	if (sort(A, B))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}