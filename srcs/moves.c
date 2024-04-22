/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:18:47 by gostr             #+#    #+#             */
/*   Updated: 2024/04/21 19:18:47 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_z_move(t_map *map, t_glob *glob)
{
	if (((map->map[map->y - 1][map->x]) != '1') && \
		(map->map[map->y - 1][map->x]))
	{
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[BACKGROUND], map->x * 32, map->y * 32);
		ft_coin_count(&glob->map);
		map->y -= 1;
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[PLAYER], map->x * 32, map->y * 32);
		ft_door(map, glob);
	}
}

void	ft_s_move(t_map *map, t_glob *glob)
{
	if (((map->map[map->y + 1][map->x]) != '1') && \
		(map->map[map->y + 1][map->x]))
	{
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[BACKGROUND], map->x * 32, map->y * 32);
		ft_coin_count(&glob->map);
		map->y += 1;
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[PLAYER], map->x * 32, map->y * 32);
	}
	ft_door(map, glob);
}

void	ft_d_move(t_map *map, t_glob *glob)
{
	if (((map->map[map->y][map->x + 1]) != '1') &&
		(map->map[map->y][map->x + 1]))
	{
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[BACKGROUND], map->x * 32, map->y * 32);
		ft_coin_count(&glob->map);
		map->x += 1;
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[PLAYER], map->x * 32, map->y * 32);
	}
	ft_door(map, glob);
}

void	ft_q_move(t_map *map, t_glob *glob)
{
	if (((map->map[map->y][map->x - 1]) != '1') &&
		(map->map[map->y][map->x - 1]))
	{
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[BACKGROUND], map->x * 32, map->y * 32);
		ft_coin_count(&glob->map);
		map->x -= 1;
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
			glob->assets.img[PLAYER], map->x * 32, map->y * 32);
		ft_door(map, glob);
	}
}
