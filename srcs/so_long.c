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
	t_glob	glob;

	if (arc != 2)
		ft_exit(NULL, "Error: Not enough args. \n");
	ft_parse_the_map(argv[1], &glob.map);
	ft_check_map(&glob.map);
	ft_start_mini(&glob);
	//ft_exit(&glob.map, "lets go\n");
}
