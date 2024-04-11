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

void	ft_free_things(t_map *map)
{
	if (map->map)
		ft_free_tab(map->map);
	if (map->clone_map)
		ft_free_tab(map->clone_map);
	free(map);
}

void	ft_exit(t_map *map, char *msg)
{
	if (map)
		ft_free_things(map);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
