/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:23:12 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/05 18:47:40 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_strrchr(const char *s, int x)
{
	int	i;

	i = (int) ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)x)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}


int	ft_strncmp(const char *s1, const char *s2, size_t x)
{
	unsigned int	i;

	i = 0;
	if (x == i)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < x - 1)
		i++;
	return ((unsigned char )s1[i] - (unsigned char )s2[i]);
}
