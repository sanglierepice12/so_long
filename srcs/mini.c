/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:01 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/17 13:55:01 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_key(int keycode, t_glob *glob)
{
	size_t i;
	size_t j;

	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
		ft_exit_success(glob, "You forced close the window.\n", 0);
	if (keycode == 122) //Z
	{
		i = 0;
		j = 0;
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, glob->background.img, i, j);
		mlx_put_image_to_window(glob->data.mlx, glob->data.win, glob->background.img, 150, 150);
		printf("%zu, %zu\n", i, j);
	}
/*	i = 0;
	while (i <= glob->map.y)
	{
		j = 0;
		while (j <= glob->map.x)
		{
			mlx_put_image_to_window(glob->data.mlx, glob->data.win, glob->background.img, i, j);
			j++;
		}
		i++;
	}*/
/*	if (keycode == 113) //Q
		move_right(glob);
	if (keycode == 115) //S
		move_right(glob);
	if (keycode == 100) //D
		move_right(glob);*/
	return (0);
}

int	close_window(t_glob *glob)
{
	ft_exit_success(glob, "You forced close the window.\n", 0);
	return (0);
}

void	ft_start_mini(t_glob *glob)
{
	glob->data.mlx = mlx_init();
	if (!glob->data.mlx)
		ft_exit(&glob->map, "Error: mlx_init failed.\n");
	glob->data.win = mlx_new_window(glob->data.mlx, 800, 800, "so fk long");
	if (!glob->data.win)
	{
		mlx_destroy_display(glob->data.mlx);
		ft_exit(&glob->map, "Error: mlx_win failed.\n");
	}
	ft_load_img(glob);
	mlx_hook(glob->data.win, 17, 1L << 0, close_window, glob);
	mlx_hook(glob->data.win, 2, 1L << 0, handle_key, glob);
	mlx_loop(glob->data.mlx);
}
