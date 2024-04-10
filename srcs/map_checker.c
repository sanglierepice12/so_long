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

static size_t	ft_map_len_check_side(char **str, t_map *map)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][j - 1] != '1')
			ft_exit(map, "Error: Miss a wall, go back to work !\n");
		i++;
	}
	return (i);
}

void	ft_check_wall(t_map *map)
{
	size_t	y;
	size_t	i;
	char	*map_z;
	char	*map_e;

	i = 0;
	y = ft_map_len_check_side(map->map, map);
	map_z = ft_strdup(map->map[0]);
	map_e = ft_strdup(map->map[y - 1]);
	while (map_z[i] && map_e[i])
	{
		if (map_z[i] != '1' || map_e[i] != '1')
		{
			free(map_e);
			free(map_z);
			ft_exit(map, "Error: Miss a wall, go back to work !\n");
		}
		i++;
	}
	free(map_e);
	free(map_z);
}

void	ft_check_token(t_map *map)
{
	size_t	i;
	size_t	j;
	int		token[3];

	token[0] = 0;
	token[1] = 0;
	token[2] = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
				token[0] += 1;
			if (map->map[i][j] == 'P')
				token[1] += 1;
			if (map->map[i][j] == 'C')
				token[2] += 1;
			j++;
		}
		i++;
	}
	if (token[0] != 1)
		ft_exit(map, "Error: To much exit, destroy one. [map_check]\n");
	if (token[1] != 1)
		ft_exit(map, "Error: Wrong number of players, kill one. [map_check]\n");
	if (token[0] == 0)
		ft_exit(map, "Error: Not enough coins, go make cash. [map_check]\n");
}

void	ft_check_map(t_map *map)
{
	ft_check_len(map);
	ft_check_wall(map);
	ft_check_token(map);
}