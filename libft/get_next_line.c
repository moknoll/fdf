/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:02:26 by mknoll            #+#    #+#             */
/*   Updated: 2025/01/24 09:53:21 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_line(int fd, char *left_c, char *buffer);
static char	*seperate(char *line);
char		*ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*stat_char;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, stat_char, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(stat_char);
		stat_char = NULL;
		return (NULL);
	}
	stat_char = seperate(line);
	return (line);
}

static char	*seperate(char *line_buffer)
{
	char	*stat_char;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	stat_char = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*stat_char == 0)
	{
		free(stat_char);
		stat_char = NULL;
	}
	line_buffer[i + 1] = 0;
	return (stat_char);
}

static char	*fill_line(int fd, char *stat_char, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!stat_char)
			stat_char = ft_strdup("");
		tmp = stat_char;
		stat_char = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stat_char);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}
