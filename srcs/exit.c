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
		ft_free_tab(map->map);
}

void	ft_exit(t_map *map)
{
	if (map)
		ft_free_things(map);
	exit(EXIT_FAILURE);
}