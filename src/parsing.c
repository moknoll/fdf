/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:10 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/07 15:12:32 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*get_column(char *line, int *width)
{
	char	**result;
	int		*numbers;
	int		i;

	i = 0;
	result = ft_split(line, ' ');
	if (!result)
		return (NULL);
	numbers = malloc(sizeof(int) * (*width));
	if (!numbers)
	{
		free(result);
		return (NULL);
	}
	while (i < *width)
	{
		numbers[i] = ft_atoi(result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (numbers);
}

int	fd_open(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

t_map	*allocate_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	map->grid = malloc(sizeof(int *) * map->height);
	if (!map->grid)
	{
		perror("Memory allocation failed for grid");
		return (free(map), NULL);
	}
	return (map);
}

t_map	*get_map(t_map *map, const char *filename)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	map = allocate_map(map);
	map->height = get_map_height(filename);
	if (map->height == 0)
		return (free(map), NULL);
	fd = fd_open(filename);
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->width = get_map_width(line);
		map->grid[i] = get_column(line, &map->width);
		if (!map->grid[i])
			return (free(line), free(map), close(fd), NULL);
		free(line);
		i++;
	}
	close(fd);
	return (map);
}
