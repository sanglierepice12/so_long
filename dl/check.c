/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:19:49 by gostr             #+#    #+#             */
/*   Updated: 2024/04/08 11:19:49 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_check_ext(char *argv, t_map *map)
{
	size_t	len;

	len = ft_strlen(argv);
	if (ft_strncmp(argv + (len - 4), ".ber", 4))
		ft_exit(map, "Error: Wrong extension [check]\n");
	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1)
		ft_exit(map, "Error: Problem with fd [check]\n");
}

void	ft_parse_the_map(char *argv)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error: Calloc [check]", 2);
		exit(EXIT_FAILURE);
	}
	ft_check_ext(argv, map);
	ft_map_validator(map);
	if (!map->x)
		ft_exit(map, "Error: No map available.\n");
	close(map->fd);
	printf("x =%d, y =%d", map->x, map->y);
	ft_free_things(map);
}
