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

int	main(int arc, char **argv)
{
	//t_map	*map;
	t_mlx so_long;

	if (arc != 2)
		ft_exit(NULL, "Error: Not enough args. \n");
	/*map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit(NULL, "Error: Calloc crash.\n");*/
	ft_parse_the_map(argv[1], &so_long.map);
	ft_check_map(&so_long.map);
	ft_start_mini();
	ft_exit(&so_long.map, "lets go\n");
}
