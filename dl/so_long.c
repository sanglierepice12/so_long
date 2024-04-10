/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:49:23 by gostr             #+#    #+#             */
/*   Updated: 2024/04/04 14:50:32 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int arc, char **argv)
{
	if (arc != 2)
		return (ft_putstr_fd("Error: arguments", 2), EXIT_FAILURE);
	ft_parse_the_map(argv[1]);
	return (EXIT_SUCCESS);
}
