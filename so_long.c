/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:30 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/08 15:57:42 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void ft_error()
{
	ft_putstr("Error:");
	exit (1);
}

int line(char *map)
{
	int	fd;
	int	lines;
	char *s;

	lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error();
	s = get_next_line(fd);
	if (!s)
		ft_error();
	lines++;
	while (s)
	{
		s = get_next_line(fd);
		lines++;
	}
	if (!s)
		lines--;
	
	printf("%d\n", lines);
	return(lines);
}

void read_map(char *map, t_long *data)
{
	int	fd;
	int	i;

	fd = open(map,O_RDONLY);
	if (fd == -1)
		ft_error();
	data->line = line(map);
	data->map = malloc(sizeof(char *) * data->line + 1);
	data->map[0] = get_next_line(fd);
	i = 0;
	while (++i < data->line)
		data->map[i] = get_next_line(fd);
	data->map[i] = NULL;
	data->col = ft_strlen(data->map[i - 1]) - 1;
	data->line--;
	printf("%d-\n", (int) ft_strlen(data->map[i - 1]));
	i = 0;
	// while (s[i])
	// 	printf("%s", s[i++]);
}

void check_file_extension(char *av)
{
	if (ft_strrchr (av, '.'))
	{
		if (av[0] == '.')	
			ft_error();
		if (strcmp(ft_strrchr (av, '.'), ".ber") != 0) // system
			ft_error();
	}
	else
		ft_error();
}
void check_new_line(t_long *data)
{
	int i;
	
	i = 0;
	while (i <= data->line)
	{
		if (data->map[i][0] == '\n')
			ft_error();
		i++;
	}
	if (data->map[data->line][data->col] == '\n')
		ft_error();
}
void check_wall(t_long *data)
{
	int i;
	
	i = 0;
	while (i <= data->col)
	{
		if (data->map[0][i] != '1' || data->map[data->line][i] != '1')
			ft_error();
		i++;
	}
	i = 1;
	while (i <= data->line - 1)
	{
		if (data->map[i][0] != '1' || data->map [i][data->col] != '1')
			ft_error();
		i++;
	}

}

void check_exit_collectible_player(t_long *data)
{
	int i;
	int j;
	int player;
	int collectible;
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
			else if (data->map[i][j] != 'C' && data->map[i][j] != 'E' && data->map[i][j] != 'P' && data->map[i][j] != '1' && data->map[i][j] != '0')
				ft_error();
			j++;
		}
		i++;
	}
	if (collectible < 1 || player != 1 || exit != 1)
		ft_error();
}

void	check_size(t_long *data)
{
	int i;
	int j;

	i = 1;
	j = ft_strlen(data->map[0]);
	while (i < data->line)
	{
		if (j != (int) ft_strlen(data->map[i]))
			ft_error();
		i++;
	}	
	if (j != (int) ft_strlen(data->map[i]) + 1)
		ft_error();
}
void check_map(t_long *data)
{	 
	check_new_line(data);
	check_wall(data);
	check_exit_collectible_player(data);
	check_size(data);
}
int	main(int ac,char **av) 
{
	int i;
	t_long data;
	
	i = 0;
	if (ac != 2)
	{
		ft_putstr("Error: invalid number of arguments\n");
		return (1);
	}
	check_file_extension(av[1]);
	read_map(av[1], &data);
	check_map(&data);

}

