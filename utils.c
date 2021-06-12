#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t	n)
{
	size_t	i;

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

void	close_program(void)
{
	write(1, "Error", 5);
	exit(-1);
}

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58) || (c == '-'))
		return (1);
	return (0);
}

int	ft_atoi(char *str, t_list **list)
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
		if (result > INT32_MAX || result < INT32_MIN)
			{
				if (list)
					free(list); /** ПРАВИЛЬНО ЛИ? нужно очистить весь лист*/
				close_program();
			}
		str++;
	}
	return ((int)result * znak);
}
