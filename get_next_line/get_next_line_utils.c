/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:50:39 by atuliara          #+#    #+#             */
/*   Updated: 2022/11/18 16:57:00 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	i++;
	return (i);
}

char	*ft_strjoin(char *stat_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!stat_str)
	{
		stat_str = (char *)malloc(1 * sizeof(char));
		stat_str[0] = '\0';
	}
	if (!stat_str || !buffer)
		return (NULL);
	new = malloc(ft_strlen((char *)stat_str) + ft_strlen((char *)buffer) + 1);
	if (!new)
		return (NULL);
	j = 0;
	i = -1;
	while (stat_str[++i] != '\0')
		new[i] = stat_str[i];
	while (buffer[j] != '\0')
		new[i++] = buffer[j++];
	new[ft_strlen((char *)stat_str) + ft_strlen((char *)buffer)] = '\0';
	free(stat_str);
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
