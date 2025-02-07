/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:37:57 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/07 15:13:28 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	get_map_width(char *line)
{
	int		width;
	char	**split;

	width = 0;
	split = ft_split(line, ' ');
	while (split[width])
		width++;
	free_tab(split);
	return (width);
}

int	get_map_height(const char *filename)
{
	int		fd;
	t_map	*map_data;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	map_data = malloc(sizeof(t_map));
	if (!map_data)
		perror("malloc failed");
	map_data->height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map_data->height == 0)
			map_data->width = get_map_width(line);
		map_data->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(map_data);
	return (map_data->height);
}