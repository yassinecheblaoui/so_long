/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:23:12 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/17 23:04:57 by yachebla         ###   ########.fr       */
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
void	ft_putnbr(int x)
{
	if (x < 0)
	{
		ft_putchar('-');
		ft_putnbr(x * (-1));
	}
	else if (x >= 10)
	{
		ft_putnbr(x / 10);
		ft_putchar(x % 10 + '0');
	}
	else
	{
		ft_putchar(x + '0');
	}
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
