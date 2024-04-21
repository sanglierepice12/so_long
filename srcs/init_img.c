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

void	ft_check_fd_assets(t_glob *glob, t_mlx *data, t_assets *assets)
{
	if ((open("./assets/bg.xpm", O_RDONLY) == -1))
		ft_exit_success(glob, "Error: Cannot access to bg. [ini_img]\n", 2);
	if ((open("./assets/coin.xpm", O_RDONLY)) == -1)
		ft_exit_success(glob, "Error: Cannot access to coin. [ini_img]\n", 2);
	if ((open("./assets/door.xpm", O_RDONLY)) == -1)
		ft_exit_success(glob, "Error: Cannot access to door. [ini_img]\n", 2);
	if ((open("./assets/wall.xpm", O_RDONLY)) == -1)
		ft_exit_success(glob, "Error: Cannot access to wall. [ini_img]\n", 2);
	if ((open("./assets/player.xpm", O_RDONLY)) == -1)
		ft_exit_success(glob, "Error: Cannot access to player. [ini_img]\n", 2);
	assets->img[BACKGROUND] = \
		mlx_xpm_file_to_image(data->mlx, \
		"./assets/bg.xpm", &assets->h, &assets->h);
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
}

static void	ft_check_and_init_img(t_glob *glob)
{
	glob->assets.h = 32;
	ft_check_fd_assets(glob, &glob->data, &glob->assets);
}

void	ft_load_img(t_glob *glob)
{
	ft_check_and_init_img(glob);
	//ft_img_to_screen()
	/*size_t i;
	size_t j;

	char *path = "assets/bg.xpm";
	glob->background.height = 32;
	glob->background.width = 32;
	glob->background.img =
	i = 0;
	while (i <= glob->map.height * 32)
	{
		printf("%zu\n", glob->map.height);
		j = 0;
		while (j <= glob->map.width * 32)
		{
			mlx_put_image_to_window(glob->data.mlx, glob->data.win, glob->background.img, i, j);
			j+= 32;
		}
		i+= 32;
	}*/
}
