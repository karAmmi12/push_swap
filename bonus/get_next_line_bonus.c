/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:04 by kammi             #+#    #+#             */
/*   Updated: 2024/02/09 17:00:40 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_fill(int fd, char *data)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(data, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (data)
				free(data);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		data = ft_strjoin(data, buffer);
	}
	free(buffer);
	return (data);
}

char	*ft_extract_line(char *data)
{
	char	*line;
	int		i;
	size_t	len;

	if (data[0] == '\0')
		return (NULL);
	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	len = i + (data[i] == '\n');
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strcpy_nls(line, data, 1);
	return (line);
}

char	*ft_update_data(char *old_data)
{
	char	*new_data;
	int		i;

	i = 0;
	while (old_data[i] && old_data[i] != '\n')
		i++;
	if (old_data[i] == '\0')
	{
		free(old_data);
		return (NULL);
	}
	new_data = malloc(sizeof(char) * (ft_strlen(old_data + i) + 1));
	if (!new_data)
		return (NULL);
	ft_strcpy_nls(new_data, old_data + i + 1, 0);
	free(old_data);
	return (new_data);
}

char	*get_next_line(int fd, int error)
{
	static char	*data;
	char		*line;

	if (error == 1)
		return (free(data), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = ft_fill(fd, data);
	if (!data)
		return (NULL);
	line = ft_extract_line(data);
	data = ft_update_data(data);
	return (line);
}
