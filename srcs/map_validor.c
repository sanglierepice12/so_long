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

void	ft_map_len(t_map *map)
{
	char	*line;
	int		i;
	int		len;

	line = gnl(map->fd);
	if (!line)
		return ;
	map->len = ft_strlen(line);
	free(line);
	i = 0;
	while (1)
	{
		line = gnl(map->fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (map->len != len)
			ft_exit(map,"Error: Map is not valid (len) [mv]\n");
		free(line);
		i++;
	}
}