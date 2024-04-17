/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:55:01 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/17 13:55:01 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_key(int keycode, t_mlx *data)
{
	if (keycode == 102)
		ft_exit_success(data, "Bisous.\n");
	return 0;
}

/*size_t	ft_double_strlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**double_dup(char **str)
{
	size_t	i;
	char	**dup;

	dup = ft_calloc(ft_double_strlen(str), sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = ft_strdup(str[i]);
		i++;
	}
	return (dup);
}*/

void	ft_start_mini()
{
	t_mlx	data;

/*	data.hou = double_dup(map->map);
	printf("str = %s\n", data.hou[0]);
	ft_free_map(map);
	ft_free_tab(data.hou);
	exit(0);*/
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(0);
	data.win = mlx_new_window(data.mlx, 800, 800, "so fk long");
	if (!data.win)
		exit(0);
	mlx_hook(data.win, 2, 1L<<0, handle_key, &data);
	mlx_loop(data.mlx);
}