/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utilise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:23:12 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/07 11:19:30 by yachebla         ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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
		ft_putchar(x + '0');
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
