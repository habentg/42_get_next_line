/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.abudhabi42.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:19:46 by hatesfam          #+#    #+#             */
/*   Updated: 2023/02/14 21:46:11 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	sizetotal;
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (sizetotal + 1));
	if (!new_str || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[sizetotal] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strchr(const char *str, int c)
{
	int			i;
	const char	*newval;

	i = 0;
	if (c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return ((char *)&str[i]);
	}
	while (*str != '\0')
	{
		while ((unsigned char)*str == (unsigned char)c)
		{
			newval = str;
			return ((char *)newval);
		}
		str++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t element_count, size_t element_size)
{
	char	*res;

	res = malloc(element_size * element_count);
	if (!res)
		return (NULL);
	ft_bzero(res, element_size * element_count);
	return (res);
}
