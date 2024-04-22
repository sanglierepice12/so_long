/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:08:01 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/19 17:08:01 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_img_to_win(t_map *map, t_glob *glob, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
				glob->assets.img[WALL], j * 32, i * 32);
	if (map->map[i][j] == '0')
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
				glob->assets.img[BACKGROUND], j * 32, i * 32);
	if (map->map[i][j] == 'C')
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
				glob->assets.img[COIN], j * 32, i * 32);
	if (map->map[i][j] == 'P')
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
				glob->assets.img[BACKGROUND], j * 32, i * 32);
	if (map->map[i][j] == 'E')
	{
		map->exit_x = (size_t)i;
		map->exit_y = (size_t)j;
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
				glob->assets.img[BACKGROUND], j * 32, i * 32);
	}
}

void	ft_img_to_map(t_map *map, t_glob *glob)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ft_img_to_win(map, glob, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(glob->data.mlx, glob->data.win, \
				glob->assets.img[PLAYER], map->x * 32, map->y * 32);
}

void	a_load(t_glob *glob)
{
	ft_img_to_map(&glob->map, glob);
}
