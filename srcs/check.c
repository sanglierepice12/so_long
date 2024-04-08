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

static void	ft_check_open(char *argv)
{
	if (open(argv, O_RDONLY) == -1)
		exit(EXIT_FAILURE);
}

static void	ft_check_ext(char *argv)
{
	size_t	len;
	len = ft_strlen(argv);
	if (ft_strncmp(argv + (len - 4), ".ber", 4))
		exit(EXIT_FAILURE);
}

void	ft_parse_the_map(char *argv)
{
	ft_check_ext(argv);
	ft_check_open(argv);
}