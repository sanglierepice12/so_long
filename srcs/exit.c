/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:19:33 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/10 13:19:33 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free_map(t_map *map)
{
	if (map->map)
		ft_free_tab(map->map);
	if (map->clone_map)
		ft_free_tab(map->clone_map);
}

void	ft_destroy(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_exit(t_map *map, char *msg)
{
	if (map)
		ft_free_map(map);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_exit_success(t_glob *glob, char *msg, int flag)
{
	ft_free_map(&glob->map);
	ft_destroy(&glob->data);
	ft_putstr_fd(msg, 1);
	exit(flag);
}
