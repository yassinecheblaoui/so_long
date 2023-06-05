/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:03:50 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/05 18:47:55 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_long
{
	char *map;
} t_long;

// size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strrchr(const char *s, int x);
int	ft_strncmp(const char *s1, const char *s2, size_t x);




#endif