/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:03:50 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/17 23:05:28 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
#include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_long
{
	char	**map;
	int		line;
	int		col;
	int		collectible;
	int		action;
	void	*mlx;
	void	*player;
	void	*background;
	void	*wall;
	void	*collect;
	void	*exit;
	int		width;
	int		height;
	void	*window;
}t_long;

typedef struct s_pos
{
	int	line;
	int	col;
}t_pos;

// size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int x);
char	*ft_strrchr(const char *s, int x);
int		ft_strncmp(const char *s1, const char *s2, size_t x);

#endif
