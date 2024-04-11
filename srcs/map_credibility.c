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

/*
static void	ft_map_filler(char **map, size_t x, size_t y)
{
	if (map[x][y] != '1' && map[x][y] != 'O')
	{
		map[x][y] = 'O';
		ft_map_filler(map, x - 1, y);
		ft_map_filler(map, x + 1, y);
		ft_map_filler(map, x, y - 1);
		ft_map_filler(map, x, y + 1);
	}
}
*/

char	**ft_clone_map(t_map *map)
{
	char	**map_clone;
	size_t	i;

	map_clone = ft_calloc(map->len, sizeof(char *));
	if (!map_clone)
		ft_exit(map, "Error: Calloc failed. [map_cred]\n");
	i = 0;
	while (map->map[i])
	{
		map_clone[i] = strdup(map->map[i]);
		if (!map_clone[i])
			ft_exit(map, "Error: Calloc failed. [map_cred]\n");
		i++;
	}
	return (map_clone);
}

void	ft_map_is_available(t_map *map)
{
	char	**clone_map;

	clone_map = ft_clone_map(map);
	if (!clone_map)
		ft_exit(map, "Error: dup_clone crash [map_cred]");
	//ft_map_filler(clone_map, map->x, map->y);
	ft_check_token(map, 1);
}
