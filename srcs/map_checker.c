/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:38:11 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/10 14:38:11 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_check_len(t_map *map)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map->map[0]);
	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != len)
			ft_exit(map, "Error: Map is not at the good len. [map_checker]\n");
		i++;
	}
}

void	ft_check_map(t_map *map)
{
	ft_check_len(map);
}