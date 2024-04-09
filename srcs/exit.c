/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:02:10 by gostr             #+#    #+#             */
/*   Updated: 2024/04/08 18:02:10 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free_things(t_map *map)
{
	if (map->map)
		free(map->map);
	free(map);
}

void	ft_exit(t_map *map, char *msg)
{
	if (map)
		ft_free_things(map);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}