/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:48:35 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/07 11:51:44 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->line)
	{
		j = 0;
		while (j <= data->col)
		{
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, \
				data->player, j * 64, i * 64);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, \
				data->wall, j * 64, i * 64);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, \
				data->exit, j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, \
				data->collect, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_write(int i)
{
	ft_putnbr(i);
	write (1, "\n", 1);
}

void	set_image(t_long *data)
{
	data->player = mlx_xpm_file_to_image(data->mlx, \
			"./textures/player.xpm", &data->width, &data->height);
	data->background = mlx_xpm_file_to_image(data->mlx, \
			"./textures/background.xpm", &data->width, &data->height);
	data->wall = mlx_xpm_file_to_image(data->mlx, \
			"./textures/wall.xpm", &data->width, &data->height);
	data->collect = mlx_xpm_file_to_image(data->mlx, \
			"./textures/collect.xpm", &data->width, &data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, \
			"./textures/exit.xpm", &data->width, &data->height);
	protect(data);
	put_image_to_window(data);
}
