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

int	key_hook(int keycode, t_mlx *data)
{
	printf("Hello from key_hook!\n");
	printf("keycode = %d\n", keycode);
	if (keycode == 102)
	{
		mlx_destroy_display(data->mlx);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

void	ft_start_mini(t_map *map)
{
	t_mlx	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		ft_exit(map, "Error: mlx failed.\n");
	data.win = mlx_new_window(data.mlx, 800, 800,"So long baybe");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		ft_exit(map, "Error: mlx window failed.\n");
	}
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	free(data.mlx);
}
