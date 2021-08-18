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

static void	write_list(char **str, t_list **A)
{
	char	**ptr;
	t_list	*temp;
	int		flag;
	int		number;

	ptr = str;
	while (*ptr)
	{
		flag = check_str2(*ptr);
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
	char	buffer[1024];
	int		byte_was_read;
	int		i;

	i = 0;
	if (!(line) || (read(0, &buffer[i], 0) < 0))
		return (-1);
	byte_was_read = read(0, &buffer[i], 1);
	while (byte_was_read > 0 && buffer[i] != '\n')
		byte_was_read = read(0, &buffer[++i], 1);
	buffer[i] = '\0';
	if (byte_was_read != -1)
	{
		*line = malloc(sizeof(char) * i);
		if (*line)
		{
			i = -1;
			while (buffer[++i])
				(*line)[i] = buffer[i];
			(*line)[i] = '\0';
		}
	}
	if (byte_was_read > 0)
		return (1);
	return (byte_was_read);
}

static t_size	init(t_list *A, t_list *B)
{
	t_size	len;

	len.size_a = ft_lstsize(A);
	len.size_b = ft_lstsize(B);
	return (len);
}

void	read_argv(t_list **A, t_list **B)
{
	char	*line;
	t_size	len;

	line = NULL;
	len = init(*A, *B);
	while (get_next_line_mod(&line))
	{
		check(A, B, line, &len);
		free(line);
		line = 0x0;
	}
	if (line)
	{
		free(line);
		line = 0x0;
	}
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
	read_argv(&A, &B);
	if (sort(A, B))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&A);
	free_list(&B);
	return (0);
}
