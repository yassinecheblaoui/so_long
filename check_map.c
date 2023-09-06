/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:43:33 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/06 17:29:42 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_line(t_long *data)
{
	int	i;

	i = 0;
	while (i <= data->line)
	{
		if (data->map[i][0] == '\n')
			ft_protect(1);
		i++;
	}
	if (data->map[data->line][data->col] == '\n')
		ft_protect(1);
}

void	check_size(t_long *data)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen(data->map[0]);
	while (i < data->line)
	{
		if (j != (int) ft_strlen(data->map[i]))
			ft_protect(1);
		i++;
	}
	if (j != (int) ft_strlen(data->map[i]) + 1)
		ft_protect(1);
}

void	check_exit_collectible_player(t_long *data, int e, int c, int p)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= data->line)
	{
		j = 1;
		while (j <= data->col - 1)
		{
			if (data->map[i][j] == 'C')
				c++;
			else if (data->map[i][j] == 'P')
				p++;
			else if (data->map[i][j] == 'E')
				e++;
			else if (data->map[i][j] != 'C' && data->map[i][j] != 'E' &&
					data->map[i][j] != 'P' && data->map[i][j] != '1' &&
					data->map[i][j] != '0')
				ft_protect(1);
			j++;
		}
	}
	if (c < 1 || p != 1 || e != 1)
		ft_protect(1);
	data->collectible = c;
}

void	check_wall(t_long *data)
{
	int	i;

	i = 0;
	while (i <= data->col)
	{
		if (data->map[0][i] != '1' || data->map[data->line][i] != '1')
			ft_protect(1);
		i++;
	}
	i = 1;
	while (i <= data->line - 1)
	{
		if (data->map[i][0] != '1' || data->map [i][data->col] != '1')
			ft_protect(1);
		i++;
	}
}

void	check_file_extension(char *av)
{
	if (ft_strrchr (av, '.'))
	{
		if (av[0] == '.')
			ft_protect(1);
		if (ft_strcmp(ft_strrchr (av, '.'), ".ber") != 0)
			ft_protect(1);
	}
	else
		ft_protect(1);
}
