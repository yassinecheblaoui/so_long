/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:46:01 by yachebla          #+#    #+#             */
/*   Updated: 2023/09/06 13:28:04 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void copyMap(t_long *data) 
{
    int i;
    int j;

    data->copiedMap = malloc(sizeof(char *) * (data->line + 1));
    printf("%d\n", data->col);
    i = 0;
    while (data->map[i])
    {
        data->copiedMap[i] = malloc(sizeof(char) * (data->col + 1));
        j = 0;
        while (data->map[i][j]) 
        {
            data->copiedMap[i][j] = data->map[i][j];
            j++;
        }
        data->copiedMap[i][j] = '\0';
        i++;
    }
    data->copiedMap[i] = NULL;
}
int	ft_position_player(char **map, int i, int j)
{
    
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
    {
        map[i + 1][j] = 'P';
        ft_position_player(map, i + 1, j);
    }
    else if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
    {
        map[i - 1][j] = 'P';
        ft_position_player(map, i - 1, j);
    }
    else if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
    {
        map[i][j + 1] = 'P';
        ft_position_player(map, i, j + 1);
    }
    else if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
    {
        map[i][j - 1] = 'P';
        ft_position_player(map, i, j - 1);
    }
    return (0);
}

void    check_exit(t_long *data)
{
    int i;
    int j;
    
    i = 0;
    while (data->copiedMap[i])
    {
        j = 0;
        while(data->copiedMap[i][j])
        {
            if (data ->copiedMap[i][j] == 'E')
            {
                if(data -> copiedMap[i - 1][j] != 'P' && data->copiedMap [i + 1][j] != 'P'
                    && data -> copiedMap[i][j - 1] !='P' && data->copiedMap [i][j + 1] != 'P')
                    ft_putstr("Error: in map\n");
            }
            j++;
        }
        i++;
    }
}

void    check_collect(t_long *data)
{
    int i;
    int j;
    int c;
    
    i = 0;
    c = 0;
    while (data->copiedMap[i])
    {
        j = 0;
        while (data->copiedMap[i][j])
        {
            if (data->copiedMap[i][j] == 'C')
                c++;
        j++;
        }
        if (c > 0)
            ft_protect(1);
    i++;
    }
}

void    check_path(t_long *data)
{
    t_pos p;

    p = position_player(*data);
    copyMap(data);
    ft_position_player(data->copiedMap, p.line, p.col);
    check_collect(data);
    
        
    // check_exit(data);
}

// int    check_exit(t_long *data, int i, int j)
// {
//     if(data->copiedMap[i + 1][j] != 'P')
//     {
//         ft_protect(1);
//         check_exit(data, i + 1, j);
//     }
//     if(data->copiedMap[i - 1][j] != 'P')
//     {
//         ft_protect(1);
//         check_exit(data, i - 1, j);
//     }
//     if(data->copiedMap[i][j + 1] != 'P')
//     {
//         ft_protect(1);
//         check_exit(data, i, j + 1);
//     }
//     if(data->copiedMap[i][j - 1] != 'P')
//     {
//         ft_protect(1);
//         check_exit(data, i, j - 1);
//     }
// }

// int isPlayerPathBlocked(t_long *data) 
// {
//     t_long playerPosition;

//     playerPosition = data->map;
//     if (data->map[line][col - 1] == 'P')
//         return 0;
//     if (data->map[line][col + 1] == 'P')
//         return 0;
//     if (data->map[line - 1][col] == 'P')
//         return 0;
//     if (data->map[line + 1][col] == 'P')
//         return 0;
//     return 1;
// }