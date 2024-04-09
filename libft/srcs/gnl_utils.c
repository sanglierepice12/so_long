/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:37:51 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/09 14:12:31 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_len(const char *s1)
{
	size_t	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	ft_end(char *buf)
{
	size_t	i;

	i = 0;
	if (ft_len(buf + i) == 0)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	if (s1[len] == '\n')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	unsigned int	len;
	char			*dest;

	len = 0;
	while (s2[len] && s2[len] != '\n')
		len++;
	if (s2[len] == '\n')
		len++;
	dest = (char *)malloc(sizeof(char) * (ft_len(s1) + len + 1));
	if (!dest)
		return (free((char *)s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && (!j || s2[j - 1] != '\n'))
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free((char *)s1);
	return (dest);
}
