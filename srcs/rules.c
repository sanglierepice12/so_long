/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:22:11 by gostr             #+#    #+#             */
/*   Updated: 2024/04/21 20:22:11 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_door(t_map *map, t_glob *glob)
{
	if (map->map[map->y][map->x] == 'E' && map->nc == 0)
		ft_exit_success(glob, "GG\n", 1);
	/*mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
                glob->assets.img[DOOR], glob->map.exit_y * 32, glob->map.exit_x * 32);*/
	if (map->nc == 0)
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
                glob->assets.img[DOOR], glob->map.exit_y * 32, glob->map.exit_x * 32);
}

void	ft_coin_count(t_map *map, t_glob *glob)
{
	int	i;
	int	j;
	i = map->y;
	j = map->x;
	if (map->map[map->y][map->x] == 'C')
	{
		map->map[i][j] = '0';
		if (map->nc > 0)
			map->nc -= 1;
	}
	(void)glob;
	//ft_door(map, glob);
}