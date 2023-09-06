/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:03:50 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/06 13:25:53 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_long
{
	char	**map;
	char	**copiedMap;
	int		line;
	int		col;
	int		collectible;
	int		action;
	void	*mlx;
	void	*player;
	void	*background;
	void	*wall;
	void	*collect;
	void	*exit;
	int		width;
	int		height;
	void	*window;
	int		length;
}t_long;

typedef struct s_pos
{
	int	line;
	int	col;
}t_pos;

void	check_new_line(t_long *data);
void	check_size(t_long *data);
void	check_exit_collectible_player(t_long *data);
void	check_wall(t_long *data);
void	protect(t_long *data);
void	check_file_extension(char *av);
void	read_map(char *map, t_long *data);
void	set_image(t_long *data);
int		mouvement(int key, t_long *data);
int		free_exit(t_long *data);
void	ft_protect(int x);
void	check_map(t_long *data);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putnbr(int x);
char	*ft_strrchr(const char *s, int x);
int		ft_strncmp(const char *s1, const char *s2, size_t x);
void    check_exit(t_long *data);
int		ft_position_player(char **map, int i, int j);
void 	copyMap(t_long *data) ;
void    check_path(t_long *data);
t_pos	position_player(t_long data);
void    check_collect(t_long *data);



#endif
