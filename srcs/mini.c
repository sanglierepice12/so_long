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
	if (keycode == 102)
		ft_exit_success(glob, "Bisous.\n");
	return 0;
}

void	ft_start_mini(t_glob *glob)
{
	glob->data.mlx = mlx_init();
	if (!glob->data.mlx)
		exit(0);
	glob->data.win = mlx_new_window(glob->data.mlx, 800, 800, "so fk long");
	if (!glob->data.win)
		exit(0);
	mlx_hook(glob->data.win, 2, 1L<<0, handle_key, glob);
	mlx_loop(glob->data.mlx);
}