/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:22:56 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/10 13:22:56 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_check_ext(char *argv, t_map *map)
{
	size_t	len;

	map->map = NULL;
	map->clone_map = NULL;
	map->fd = 0;
	len = ft_strlen(argv);
	if (len < 4)
		ft_exit(map, "Error: Wrong extension. [fill]\n");
	if (ft_strncmp(argv + (len - 4), ".ber", 4))
		ft_exit(map, "Error: Wrong extension. [fill]\n");
	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1)
		ft_exit(map, "Error: Problem with fd. [fill]\n");
}

char	*str_join_map(char *src, char *map_buf, t_map *map)
{
	char	*temp;
	size_t	len;
	int		i;

	len = ft_strlen(src) + ft_strlen(map_buf);
	temp = ft_calloc(len + 1, sizeof(char));
	if (!temp)
	{
		free(src);
		ft_exit(map, "Error: Calloc crash. [fill]\n");
	}
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	len = 0;
	while (map_buf[len])
	{
		temp[i] = map_buf[len];
		len++;
		i++;
	}
	free(src);
	return (temp);
}

static void	ft_fill_map_following(t_map *map, char *map_gen)
{
	map->map = ft_split(map_gen, '\n');
	if (!map->map)
		ft_exit(map, "Error: split crash. [fill]\n");
	map->clone_map = ft_split(map_gen, '\n');
	if (!map->clone_map)
		ft_exit(map, "Error: split crash. [fill]\n");
	free(map_gen);
}

static void	ft_fill_map(t_map *map)
{
	size_t	bytes;
	char	map_buf[1025];
	char	*map_gen;
	size_t	i;

	i = 0;
	map_gen = ft_calloc(1, sizeof(char));
	if (!map_gen)
		ft_exit(map, "Error: Calloc crash. [fill]\n");
	bytes = 1024;
	while (bytes == 1024)
	{
		bytes = read(map->fd, map_buf, bytes);
		if (bytes <= 0)
			ft_exit(map, "Error: Problem reading file. [fill]\n");
		map_buf[bytes] = '\0';
		map_gen = str_join_map(map_gen, map_buf, map);
		i += bytes;
		if (i == 0)
			ft_exit(map, "Nothing in the map, go back to work ! [fill]\n");
	}
	ft_fill_map_following(map, map_gen);
}

void	ft_parse_the_map(char *argv, t_map *map)
{
	ft_check_ext(argv, map);
	ft_fill_map(map);
}
