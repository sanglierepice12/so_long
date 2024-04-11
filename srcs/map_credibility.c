/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_credibility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:43:02 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/11 11:43:02 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	**ft_map_filler(char **map_clone, size_t x, size_t y, t_map *map)
{
	if (map_clone[x][y] != '1' && map_clone[x][y] != 'O')
	{
		map_clone[x][y] = 'O';
		ft_map_filler(map_clone, x - 1, y, map);
		ft_map_filler(map_clone, x + 1, y, map);
		ft_map_filler(map_clone, x, y - 1, map);
		ft_map_filler(map_clone, x, y + 1, map);
	}
	return (map_clone);
}

void	ft_map_is_available(t_map *map)
{
	map->clone_map = ft_map_filler(map->clone_map, map->y, map->x, map);
	ft_check_token(map->clone_map, map, 1);
}
