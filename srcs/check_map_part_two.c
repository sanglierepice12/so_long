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
	printf("player is in position : %d,%d\n", x, y);
}

void	ft_check_token_is_good(t_map *map, int E, int P, int C, int flag)
{
	if (C == 0 && flag == 0)
		ft_exit(map, "Error: Not enough coins, go make cash. [map_check]\n");
	if (E != 1 && flag == 0)
		ft_exit(map, "Wrong number of exit, go back to work. [map_check]\n");
	if (P != 1 && flag == 0)
		ft_exit(map, "Wrong number of players, go back to work. [map_check]\n");
	if ((E != 0 && P != 0 && C != 0) && flag == 1)
		ft_exit(map, "Error: Cannot go to the exit [map_check]\n");
	/*if (token[2] == 0 && flag == 0)
		ft_exit(map, "Error: Not enough coins, go make cash. [map_check]\n");
	if (token[0] != 1 && flag == 0)
		ft_exit(map, "Wrong number of exit, go back to work. [map_check]\n");
	if (token[1] != 1 && flag == 0)
		ft_exit(map, "Wrong number of players, go back to work. [map_check]\n");
	if ((token[1] != 0 && token[2] != 0 && token[0] != 0) && flag == 1)
		ft_exit(map, "Error: Cannot go to the exit [map_check]\n");*/
}
