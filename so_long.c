/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:30 by yachebla          #+#    #+#             */
/*   Updated: 2023/06/05 18:58:35 by yachebla         ###   ########.fr       */
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

char **read_map(char *map)
{
	int	fd;
	int	i;
	int lines;
	char **s;

	fd = open(map,O_RDONLY);
	if (fd == -1)
		ft_error();
	lines = line(map);
	s = malloc(sizeof(char *) * lines + 1);
	s[0] = get_next_line(fd);
	i = 0;
	while (++i < lines)
		s[i] = get_next_line(fd);
	s[i] = NULL;
	i = 0;
	// while (s[i])
	// 	printf("%s", s[i++]);
	return(s);
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
int	main(int ac,char **av) 
{
	char *c;
	int i;
	
	i = 0;
	if (ac != 2)
	{
		ft_putstr("Error: invalid number of arguments\n");
		return (1);
	}
	check_file_extension(av[1]);
	read_map(av[1]);	
		

}

