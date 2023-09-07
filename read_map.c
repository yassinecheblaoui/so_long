/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:44:40 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/07 11:59:04 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	line(char *map)
{
	int		fd;
	int		lines;
	char	*s;

	lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_protect(1);
	s = get_next_line(fd);
	if (!s)
		ft_protect(1);
	lines++;
	while (s)
	{
		free(s);
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
		ft_protect(1);
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

void	ft_protect(int x)
{
	if (x == 1)
		ft_putstr("Error:\n");
	if (x == 2)
		ft_putstr("Error: invalid number of arguments\n");
	exit (1);
}

void	protect(t_long *data)
{
	if (!data->player || !data->wall || !data->collect || !data->exit)
		ft_protect(1);
}
