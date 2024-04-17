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
	t_map	*map;

	if (arc != 2)
		ft_exit(NULL, "Error: Not enough args. \n");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit(NULL, "Error: Calloc crash.\n");
	ft_parse_the_map(argv[1], map);
	ft_check_map(map);
	ft_start_mini(map);
	ft_exit(map, "lets go\n");
}
