/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:00:51 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 12:02:50 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		dest[j++] = s1[i++];
	}
	if (s1)
		free(s1);
	i = 0;
	while (s2 && s2[i])
	{
		dest[j++] = s2[i++];
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strcpy_nls(char *dest, char *src, int nls)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (nls && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
