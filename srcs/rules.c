/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:22:11 by gostr             #+#    #+#             */
/*   Updated: 2024/04/21 20:22:11 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_coin_count(t_map *map, t_glob *glob)
{
	int	i;
	int	j;
	(void)glob;
	(void)map;
	i = map->y;
	j = map->x;
	if (map->map[map->y][map->x] == 'C')
	{
		map->map[i][j] = '0';
		if (map->nc > 0)
			map->nc--;
		if (map->nc == 0)
			ft_exit_success(glob, "FINISH\n", 1);
	}
}