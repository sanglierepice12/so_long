/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:02 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/18 15:36:02 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_init_xpm(t_mlx *data, t_assets *assets, t_glob *glob)
{
	assets->img[BACKGROUND] = \
			mlx_xpm_file_to_image(data->mlx, \
			"./assets/bg.xpm", &assets->h, &assets->h);
	if (assets->img[BACKGROUND] == NULL)
		ft_exit_success(glob, "Error: Cannot access to bg. [ini_img]\n", 2);
	assets->img[COIN] = \
			mlx_xpm_file_to_image(data->mlx, \
			"./assets/coin.xpm", &assets->h, &assets->h);
	assets->img[DOOR] = \
			mlx_xpm_file_to_image(data->mlx, \
			"./assets/door.xpm", &assets->h, &assets->h);
	assets->img[WALL] = \
			mlx_xpm_file_to_image(data->mlx, \
			"./assets/wall.xpm", &assets->h, &assets->h);
	assets->img[PLAYER] = \
			mlx_xpm_file_to_image(data->mlx, \
			"./assets/player.xpm", &assets->h, &assets->h);
	assets->img[ENEMY] = \
			mlx_xpm_file_to_image(data->mlx, \
			"./assets/enemy.xpm", &assets->h, &assets->h);
}

void	ft_check_fd_assets(t_glob *glob)
{
	glob->assets.fd[BACKGROUND] = open("./assets/bg.xpm", O_RDONLY);
	if (glob->assets.fd[BACKGROUND] == -1)
		ft_exit_success(glob, "Error: Cannot access to bg. [ini_img]\n", 2);
	close (glob->assets.fd[BACKGROUND]);
	glob->assets.fd[COIN] = open("./assets/coin.xpm", O_RDONLY);
	if (glob->assets.fd[COIN] == -1)
		ft_exit_success(glob, "Error: Cannot access to coin. [ini_img]\n", 2);
	close (glob->assets.fd[COIN]);
	glob->assets.fd[DOOR] = open("./assets/door.xpm", O_RDONLY);
	if (glob->assets.fd[DOOR] == -1)
		ft_exit_success(glob, "Error: Cannot access to door. [ini_img]\n", 2);
	close (glob->assets.fd[DOOR]);
	glob->assets.fd[WALL] = open("./assets/wall.xpm", O_RDONLY);
	if (glob->assets.fd[WALL] == -1)
		ft_exit_success(glob, "Error: Cannot access to wall. [ini_img]\n", 2);
	close (glob->assets.fd[WALL]);
	glob->assets.fd[ENEMY] = open("./assets/enemy.xpm", O_RDONLY);
	if (glob->assets.fd[ENEMY] == -1)
		ft_exit_success(glob, "Error: Cannot access to enemy. [ini_img]\n", 2);
	close (glob->assets.fd[ENEMY]);
	glob->assets.fd[PLAYER] = open("./assets/player.xpm", O_RDONLY);
	if (glob->assets.fd[PLAYER] == -1)
		ft_exit_success(glob, "Error: Cannot access to player. [ini_img]\n", 2);
	close (glob->assets.fd[PLAYER]);}

void	ft_init_img(t_glob *glob)
{
	glob->assets.h = 32;
	glob->map.moves = 0;
	ft_check_fd_assets(glob);
	ft_init_xpm(&glob->data, &glob->assets, glob);
	a_load(glob);
}
