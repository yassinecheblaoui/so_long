/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:50:16 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/07 11:51:30 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	position_player(t_long data)
{
	int		i;
	int		j;
	t_pos	p;

	i = 1;
	p.col = 0;
	p.line = 0;
	while (i < data.line)
	{
		j = 1;
		while (j < data.col)
		{
			if (data.map[i][j] == 'P')
			{
				p.line = i;
				p.col = j;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

void	action(t_long *data, int line, int col)
{
	t_pos	p;
	bool	i;

	i = false;
	p = position_player(*data);
	if (data->map[line][col] == 'C' || data->map[line][col] == '0')
	{
		ft_write(++data->action);
		if (data->map[line][col] == 'C')
			data->collectible--;
		data->map[line][col] = 'P';
		data->map[p.line][p.col] = '0';
		mlx_put_image_to_window(data->mlx, data->window, \
		data->player, col * 64, line * 64);
		mlx_put_image_to_window(data->mlx, data->window, \
		data->background, p.col * 64, p.line * 64);
	}
	if (data->collectible == 0)
		i = true;
	if (data->map[line][col] == 'E' && i == true)
	{
		ft_write(++data->action);
		ft_putstr("succes\n");
		exit(0);
	}
}

int	mouvement(int key, t_long *data)
{
	t_pos	p;

	p = position_player(*data);
	if (key == 13 || key == 126)
		action(data, p.line - 1, p.col);
	else if (key == 1 || key == 125)
		action(data, p.line + 1, p.col);
	else if (key == 2 || key == 124)
		action(data, p.line, p.col + 1);
	else if (key == 0 || key == 123)
		action(data, p.line, p.col - 1);
	else if (key == 53)
		exit(0);
	return (0);
}

int	free_exit(t_long *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	exit (0);
	return (0);
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
