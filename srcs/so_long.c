/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:17:18 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/10 13:17:18 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_input(int keysym, t_mlx *data)
{
	//Check the #defines
	//find / -name keysym.h 2>/dev/null
	//find / -name keysymdef.h 2>/dev/null
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

void	mini(t_map *map)
{
	t_mlx	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		ft_exit(map, "Error: mlx failed.\n");
	data.win = mlx_new_window(data.mlx, 300, 300,"So long baybe");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		ft_exit(map, "Error: mlx window failed.\n");
	}
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	mlx_key_hook(data.mlx, handle_input, &data);
	mlx_destroy_window(data.mlx, data.win);
	free(data.mlx);
}

int	main(int arc, char **argv)
{
	t_map	*map;

	if (arc != 2)
		ft_exit(NULL, "Error: Not enough args. \n");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit(NULL, "Error: Calloc crash.\n");
	ft_parse_the_map(argv[1], map);
	ft_check_map(map);
	mini(map);
	ft_exit(map, "lets go\n");
}
