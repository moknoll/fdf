/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:37:57 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/11 13:57:30 by mknoll           ###   ########.fr       */
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
	t_map	map_data;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
    {
        perror("Fehler bei oeffnen der datei");
        return (0);
    }
	map_data.height = 0;
    map_data.width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map_data.height == 0)
			map_data.width = get_map_width(line);
		map_data.height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_data.height);
}

void free_map(t_map *map)
{
    int i;

    i = 0;
    if (map)
    {
        if (map->grid)
        {
            while(i < map->height)
            {
                free(map->grid[i]);
                i++;  // Frei den Speicher für jede Zeile
            }
            free(map->grid);  // Frei den Speicher für das Grid selbst
        }
        free(map);  // Frei den Speicher für die map-Struktur
    }
}