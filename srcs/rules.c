/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:22:11 by gostr             #+#    #+#             */
/*   Updated: 2024/04/23 18:40:31 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_itoa_nc(t_map *map, t_glob *glob)
{
	map->str_moves = ft_itoa(map->moves);
	if (!map->str_moves)
		ft_exit_success(glob, "Error : Calloc failed.\n", 2);
	mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
				glob->assets.img[WALL], 0, 0);
	mlx_string_put(glob->data.mlx, glob->data.win, 15, 20, 000, map->str_moves);
	free(map->str_moves);
}

void	ft_door(t_map *map, t_glob *glob)
{
	ft_itoa_nc(map, glob);
	if (map->map[map->y][map->x] == 'E' && map->nc == 0)
		ft_exit_success(glob, "GG\n", 1);
	if (map->map[map->y][map->x] == 'X')
		ft_exit_success(glob, "YOU DIED\n", 1);
	if (map->nc == 0)
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[DOOR], glob->map.exit_y * 32, \
				glob->map.exit_x * 32);
}

void	ft_coin_count(t_map *map)
{
	int	i;
	int	j;

	map->moves += 1;
	ft_printf("Total moves = %d\n", map->moves);
	i = map->y;
	j = map->x;
	if (map->map[map->y][map->x] == 'C')
	{
		map->map[i][j] = '0';
		if (map->nc > 0)
			map->nc -= 1;
	}
}
