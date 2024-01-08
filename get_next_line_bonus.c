/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:38:37 by risasada          #+#    #+#             */
/*   Updated: 2023/07/23 16:38:40 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char		*ft_strchr(const char *str, int c);
char		*return_free(char *buffer);
char		*process_buffers(size_t line_size, char **leftovers);
char		*read_line(char **leftovers, char *buffer, int fd);

char	*get_next_line(int fd)
{
	static char		*leftovers[OPEN_MAX];
	char			*buffer;
	char			*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1 || read(fd, NULL, 0))
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (leftovers[fd] == NULL)
		leftovers[fd] = ft_strdup("");
	if (leftovers[fd] == NULL)
		return (return_free(buffer));
	line = read_line(&leftovers[fd], buffer, fd);
	return (line);
}

char	*read_line(char **leftovers, char *buffer, int fd)
{
	char	*new_line;
	ssize_t	read_size;

	new_line = ft_strchr(*leftovers, '\n');
	read_size = 0;
	while (new_line == NULL)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (return_free(buffer));
		else if (read_size == 0)
		{
			free(buffer);
			return (process_buffers(ft_strlen(*leftovers), leftovers));
		}
		buffer[read_size] = '\0';
		*leftovers = ft_strjoin(*leftovers, buffer);
		if (*leftovers == NULL)
			return (return_free(buffer));
		new_line = ft_strchr(*leftovers, '\n');
	}
	free(buffer);
	return (process_buffers(((new_line + 1) - *leftovers), leftovers));
}

char	*process_buffers(size_t line_size, char **leftovers)
{
	char	*tmp;
	char	*line;

	tmp = NULL;
	if (line_size == 0 || leftovers[0] == '\0')
	{
		free (*leftovers);
		*leftovers = NULL;
		return (NULL);
	}
	tmp = ft_substr(*leftovers, line_size, BUFFER_SIZE);
	if (tmp == NULL)
		return (NULL);
	line = ft_substr(*leftovers, 0, line_size);
	if (line == NULL)
		return (return_free(tmp));
	free(*leftovers);
	*leftovers = tmp;
	return (line);
}

char	*return_free(char *buffer)
{
	if (buffer != NULL)
		free (buffer);
	return (NULL);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(&str[i]));
		i ++;
	}
	if (c == 0)
		return ((char *)(&str[i]));
	return (NULL);
}
