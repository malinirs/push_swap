/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:57:55 by awoods            #+#    #+#             */
/*   Updated: 2021/08/17 12:57:58 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

long	ft_atoi_mod(char *str)
{
	int			znak;
	long		result;

	result = 0;
	znak = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		znak = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * znak);
}

int	ft_strchr_mod(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return (1);
		i++;
	}
	if (s[i] == cc)
		return (1);
	return (0);
}
