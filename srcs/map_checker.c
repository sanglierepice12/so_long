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
	ssize_t	j;

	i = 0;
	while (str[i])
	{
		j = ft_strlen(str[0]) - 1;
		if (str[i][0] != '1' || str[i][j] != '1')
			ft_exit(map, "Error: Miss a wall, go back to work !\n");
		/*while (str[i][j])
		{
			if ((str[i][j] != 'E') && (str[i][j] != 'P') && (str[i][j] != 'C'))
				if ((str[i][j] != '1') && (str[i][j] != '0'))
					ft_exit(map, "Error: Something looks not in the plan.\n");
			j--;
		}*/
		i++;
	}
	return (i);
}

void	ft_check_wall(t_map *map)
{
	size_t	i;
	char	*map_z;
	char	*map_e;

	i = 0;
	map->len = ft_map_len_check_side(map->map, map) - 1;
	check_invalid_element(map->map, map);
	map_z = ft_strdup(map->map[0]);
	if (!map_z)
		ft_exit(map, "Error: Calloc crash [map_check]\n");
	map_e = ft_strdup(map->map[map->len]);
	if (!map_e)
		ft_exit(map, "Error: Calloc crash [map_check]\n");
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

void	ft_check_token(char **mapper, t_map *map, int flag)
{
	ssize_t	i;
	ssize_t	j;
	int		token[3];

	ft_bzero(token, sizeof(token));
	i = -1;
	while (mapper[++i])
	{
		j = -1;
		while (mapper[i][++j])
		{
			if (mapper[i][j] == 'E')
				token[0] += 1;
			if (mapper[i][j] == 'P')
			{
				token[1] += 1;
				if (flag == 0)
					ft_find_player_pos(map, j, i);
			}
			if (mapper[i][j] == 'C')
				token[2] += 1;
		}
	}
	ft_check_token_good(map, token, flag);
}

void	ft_check_map(t_map *map)
{
	ft_check_len(map);
	ft_check_wall(map);
	ft_check_token(map->map, map, 0);
	ft_map_is_available(map);
}
