/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:22:56 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/11 11:57:19 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_find_player_pos(t_map *map, int x, int y)
{
	map->x = x;
	map->y = y;
}

void	ft_check_token_good(t_map *map, int token[3], int flag)
{
	if (token[2] == 0 && flag == 0)
		ft_exit(map, "Error: Not enough coins, go make cash. [map_check]\n");
	if (token[0] != 1 && flag == 0)
		ft_exit(map, "Wrong number of exit, go back to work. [map_check]\n");
	if (token[1] != 1 && flag == 0)
		ft_exit(map, "Wrong number of players, go back to work. [map_check]\n");
	if (flag == 1)
		if (token[0] != 0 || token[1] != 0 || token[2] != 0)
			ft_exit(map, "Error: Cannot go to the exit [map_check]\n");
	if (flag == 0)
	{
		map->np = token[1];
		map->ne = token[0];
		map->nc = token[2];
	}
}

void	check_invalid_element(char **str, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] != 'E') && (str[i][j] != 'P') && (str[i][j] != 'C'))
				if ((str[i][j] != '1') && (str[i][j] != '0'))
					if ((str[i][j] != 'X'))
						ft_exit(map, "Error: Something is not in the plan.\n");
			j++;
		}
		i++;
	}
}
