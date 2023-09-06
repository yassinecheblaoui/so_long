/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:52:30 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/05 13:06:51 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_long *data)
{
	check_new_line(data);
	check_wall(data);
	check_exit_collectible_player(data);
	check_size(data);
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
	check_path(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.window = mlx_new_window(data.mlx, (data.col + 1) * 64, \
			(data.line + 1) * 64, "so_long");
	if (!data.window)
		return (1);
	set_image(&data);
	mlx_hook(data.window, 2, 0, &mouvement, &data);
	mlx_hook(data.window, 17, 0, &free_exit, &data);
	mlx_loop(data.mlx);
	
}
