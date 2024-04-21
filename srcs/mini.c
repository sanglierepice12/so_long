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
	if (keycode == 65307)
		ft_exit_success(glob, "You closed the window.\n", 0);
	if (keycode == 122 || keycode == 65362) //Z
		ft_z_move(&glob->map, glob);
	if (keycode == 115 || keycode == 65364) //S
		ft_s_move(&glob->map, glob);
	if (keycode == 100 || keycode == 65363) //D
		ft_d_move(&glob->map, glob);
	if (keycode == 113 || keycode == 65361) //Q
		ft_q_move(&glob->map, glob);
	return (0);
}

int	close_window(t_glob *glob)
{
	ft_exit_success(glob, "You closed the window.\n", 0);
	return (0);
}

void	ft_start_mini(t_glob *glob)
{
	glob->data.mlx = mlx_init();
	if (!glob->data.mlx)
		ft_exit(&glob->map, "Error: mlx_init failed.\n");
	glob->data.win = mlx_new_window(glob->data.mlx, glob->map.width * 32, (glob->map.height + 1) * 32, "so fk long");
	if (!glob->data.win)
	{
		mlx_destroy_display(glob->data.mlx);
		ft_exit(&glob->map, "Error: mlx_win failed.\n");
	}
	ft_init_img(glob);
	mlx_hook(glob->data.win, 17, 1L << 0, close_window, glob);
	mlx_hook(glob->data.win, 2, 1L << 0, handle_key, glob);
	mlx_loop(glob->data.mlx);
}
