/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:30 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/07 17:45:54 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_long *data)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	check_new_line(data);
	check_wall(data);
	check_exit_collectible_player(data, e, c, p);
	check_size(data);
}

int	main(int ac, char **av)
{
	int		i;
	t_long	data;

	i = 0;
	if (ac != 2)
		ft_protect(2);
	check_file_extension(av[1]);
	read_map(av[1], &data);
	check_map(&data);
	check_path(&data);
	data.action = 0;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.window = mlx_new_window(data.mlx, (data.col + 1) * 64, \
		(data.line + 1) * 64, "so_long");
	if (!data.window)
		return (1);
	set_image(&data);
	write (1, "0\n", 2);
	mlx_hook(data.window, 2, 0, &mouvement, &data);
	mlx_hook(data.window, 17, 0, &free_exit, &data);
	mlx_loop(data.mlx);
}
