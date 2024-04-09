/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:55:05 by gostr             #+#    #+#             */
/*   Updated: 2024/04/09 12:55:05 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_check_wall(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			ft_exit(map, "Error: Wall is not finish, got back to work !\n");
		i++;
	}
	(void)map;
}

void	map_len_y(t_map *map)
{
	int		i;
	char	*line;
	i = 0;
	while (1)
	{
		line = gnl(map->fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	map->y = i;
}

void	map_len_x_check(t_map *map)
{
	char	*line;
	int		i;
	int		len;

	line = gnl(map->fd);
	if (!line)
		ft_exit(map, "Error: Nothing turn in .ber");
	map->x = ft_strlen(line);
	ft_check_wall(line, map);
	free(line);
	i = 0;
	while (1)
	{
		line = gnl(map->fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (map->x != len)
			ft_exit(map,"Error: Map is not valid (len) [mv]\n");
		free(line);
		i++;
	}
}

void	ft_map_validator(t_map *map)
{
	map_len_x_check(map);
	map_len_y(map);
	map_generator(map);
	//check inside map
}