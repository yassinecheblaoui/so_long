/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:30 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/18 16:10:15 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_protect()
{
	ft_putstr("Error:");
	exit (1);
}

int	line(char *map)
{
	int		fd;
	int		lines;
	char	*s;

	lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_protect();
	s = get_next_line(fd);
	if (!s)
		ft_protect();
	lines++;
	while (s)
	{
		s = get_next_line(fd);
		lines++;
	}
	if (!s)
		lines--;
	return (lines);
}

void	read_map(char *map, t_long *data)
{
	int	fd;
	int	i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_protect();
	data->line = line(map);
	data->map = malloc(sizeof(char *) * data->line + 1);
	data->map[0] = get_next_line(fd);
	i = 0;
	while (++i < data->line)
		data->map[i] = get_next_line(fd);
	data->map[i] = NULL;
	data->col = ft_strlen(data->map[i - 1]) - 1;
	data->line--;
}

void	check_file_extension(char *av)
{
	if (ft_strrchr (av, '.'))
	{
		if (av[0] == '.')
			ft_protect();
		if (strcmp(ft_strrchr (av, '.'), ".ber") != 0) // system
			ft_protect();
	}
	else
		ft_protect();
}
void	check_new_line(t_long *data)
{
	int	i;

	i = 0;
	while (i <= data->line)
	{
		if (data->map[i][0] == '\n')
			ft_protect();
		i++;
	}
	if (data->map[data->line][data->col] == '\n')
		ft_protect();
}
void	check_wall(t_long *data)
{
	int	i;

	i = 0;
	while (i <= data->col)
	{
		if (data->map[0][i] != '1' || data->map[data->line][i] != '1')
			ft_protect();
		i++;
	}
	i = 1;
	while (i <= data->line - 1)
	{
		if (data->map[i][0] != '1' || data->map [i][data->col] != '1')
			ft_protect();
		i++;
	}
}

void	check_exit_collectible_player(t_long *data)
{
	int	i;
	int	j;
	int	player;
	int	collectible;
	int	exit;

	i = 1;
	player = 0;
	collectible = 0;
	exit = 0;
	while (i <= data->line)
	{
		j = 1;
		while (j <= data->col - 1)
		{
			if (data->map[i][j] == 'C')
				collectible++;
			else if (data->map[i][j] == 'P')
				player++;
			else if (data->map[i][j] == 'E')
				exit++;
			else if (data->map[i][j] != 'C' && data->map[i][j] != 'E' &&
					data->map[i][j] != 'P' && data->map[i][j] != '1' &&
					data->map[i][j] != '0')
				ft_protect();
			j++;
		}
		i++;
	}
	if (collectible < 1 || player != 1 || exit != 1)
		ft_protect();
	data->collectible = collectible;
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
			ft_protect();
		i++;
	}	
	if (j != (int) ft_strlen(data->map[i]) + 1)
		ft_protect();
}

void check_map(t_long *data)
{
	check_new_line(data);
	check_wall(data);
	check_exit_collectible_player(data);
	check_size(data);
}

t_pos	position_player(t_long data)
{
	int i;
	int j;
	t_pos p;

	i = 1;
	p.col = 0;
	p.line = 0;
	while (i < data.line)
	{
	j = 1;
	while (j < data.col)
	{
		if ( data.map[i][j] == 'P')
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

void	protect(t_long *data)
{
	if (!data->player || !data->wall || !data->collect || !data->exit)
		ft_protect();
}

void	put_image_to_window(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->line)
	{
		printf("i = %d\n", i);
		j = 0;
		while (j <= data->col)
		{
			printf("j = %d\n", j);
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

void	action(t_long *data, int line, int col)
{
	t_pos p;
	bool	i;

	i = false;
	p = position_player(*data);
	if (data->map[line][col] == 'C' || data->map[line][col] == '0')
	{
		ft_putnbr(data->action++);
		write (1, "\n", 1);
		if (data->map[line][col] == 'C')
			data->collectible--;
		data->map[line][col] = 'P';
		data->map[p.line][p.col] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->player, col * 64, line * 64);
		mlx_put_image_to_window(data->mlx, data->window, data->background, p.col * 64, p.line * 64);
	}
	if (data->collectible == 0)
		i = true;
	if (data->map[line][col] == 'E' && i == true)
	{
		ft_putstr("succes\n");
		exit(0);
	}
	int j = 0;
	// while(data->map[j])
	// 	printf("%s", data->map[j++]);
}

int	mouvement(int key, t_long *data)
{
	t_pos p;
	
	p = position_player(*data);
	if (key == 13 || key == 126)
		action(data, p.line - 1, p.col);
	else if (key == 1 || key == 125)
		action(data, p.line + 1, p.col);
	else if (key == 2 || key == 124)
		action(data, p.line , p.col + 1);
	else if (key == 0 || key == 123)
		action(data, p.line , p.col - 1);
	else if (key == 53)
		exit(0);
	return 0;
}
int	main(int ac, char **av)
{
	int		i;
	t_long	data;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("Error: invalid number of arguments\n");
		return (1);
	}
	check_file_extension(av[1]);
	read_map(av[1], &data);
	check_map(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.window = mlx_new_window(data.mlx, (data.col + 1) * 64, \
			(data.line + 1) * 64, "so_long");
	if (!data.window)
		return (1);
	set_image(&data);
	mlx_hook(data.window, 2, 0, &mouvement, &data);
	mlx_loop(data.mlx);
}
