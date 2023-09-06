/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:46:01 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/06 17:09:24 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copymap(t_long *data)
{
	int	i;
	int	j;

	data->copiedmap = malloc(sizeof(char *) * (data->line + 1));
	i = 0;
	while (data->map[i])
	{
		data->copiedmap[i] = malloc(sizeof(char) * (data->col + 1));
		j = 0;
		while (j < data->col) 
		{
			data->copiedmap[i][j] = data->map[i][j];
			j++;
		}
		data->copiedmap[i][j] = '\0';
		i++;
	}
	data->copiedmap[i] = NULL;
}

int	ft_position_player(char **map, int i, int j)
{
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
	{
		map[i + 1][j] = 'P';
		ft_position_player(map, i + 1, j);
	}
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
	{
		map[i - 1][j] = 'P';
		ft_position_player(map, i - 1, j);
	}
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
	{
		map[i][j + 1] = 'P';
		ft_position_player(map, i, j + 1);
	}
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
	{
		map[i][j - 1] = 'P';
		ft_position_player(map, i, j - 1);
	}
	return (0);
}

void	check_exit(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->copiedmap[i])
	{
		j = 0;
		while (data->copiedmap[i][j])
		{
			if (data ->copiedmap[i][j] == 'E')
			{
				if (data -> copiedmap[i - 1][j] != 'P'
				&& data->copiedmap [i + 1][j] != 'P'
				&& data -> copiedmap[i][j - 1] != 'P'
				&& data->copiedmap [i][j + 1] != 'P')
				{
					ft_putstr("Error: in map\n");
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_collect(t_long *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (data->copiedmap[i])
	{
		j = 0;
		while (data->copiedmap[i][j])
		{
			if (data->copiedmap[i][j] == 'C')
				c++;
			j++;
		}
		if (c > 0)
		{
			ft_putstr("Error:map not work\n");
			exit(1);
		}
		i++;
	}
}

void	check_path(t_long *data)
{
	t_pos	p;

	p = position_player(*data);
	copymap(data);
	ft_position_player(data->copiedmap, p.line, p.col);
	check_collect(data);
	check_exit(data);
}
