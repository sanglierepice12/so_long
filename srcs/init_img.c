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

void	ft_load_img(t_glob *glob)
{
	(void)glob;
	char *path = "assets/bg.xpm";
	glob->background.height = 32;
	glob->background.width = 32;
	glob->background.img = mlx_xpm_file_to_image(glob->data.mlx, path, &glob->background.width, &glob->background.height);
}
