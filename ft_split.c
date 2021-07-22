#include "push_swap.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

static char	*ft_malloc_and_free(char **str, size_t	i, size_t	j, size_t
temp)
{
	str[j] = malloc(sizeof(char) * (i - temp + 1));
	if (!*str)
	{
		while (j > 0)
		{
			free(str[j]);
			j--;
		}
		free(str);
		return (NULL);
	}
	return (*str);
}

static size_t 	ft_check_nbr_str(char const	*s, char c)
{
	size_t	i;
	size_t	nb_str;
	int		flag;

	i = 0;
	nb_str = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
			nb_str++;
		if (s[i] && s[i] == c)
			i++;
	}
	return (nb_str);
}

static void	ft_nbr_index_and_copy(char const	*s, char	c, char	**str,
							  size_t	nb_str)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	while (s[i] && j < nb_str)
	{
		while (s[i] && s[i] == c)
			i++;
		temp = i;
		while (s[i] && s[i] != c)
			i++;
		if (temp < i)
		{
			if (ft_malloc_and_free(str, i, j, temp) == NULL)
				return ;
			ft_strlcpy(str[j], &s[temp], i - temp + 1);
		}
		j++;
	}
	str[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	nb_str;

	nb_str = ft_check_nbr_str(s, c);
	str = (char **)malloc(sizeof(char *) * (nb_str + 1));
	if (!str)
		return (NULL); // ОБРАБОТАТЬ !!!
	ft_nbr_index_and_copy(s, c, str, nb_str);
	return (str);
}