/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:10 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/11 14:06:18 by mknoll           ###   ########.fr       */
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
    {
        return (NULL);
    }

    numbers = malloc(sizeof(int) * (*width));
    if (!numbers)
    {
        free_tab(result);
        return (NULL);
    }

    while (i < *width)
    {
        if (!result[i])
        {
            free_tab(result);
            free(numbers);
            return (NULL);
        }
        
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
	if (!map)
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

t_map *get_map(t_map *map, const char *filename)
{
    int fd;
    int i;
    char *line;

    i = 0;

    map = allocate_map(map);  // Jetzt ist height gesetzt, allocate_map() funktioniert korrekt
    if (!map)
        return (NULL);
    
    fd = fd_open(filename);
    if (fd == -1)
        return (NULL);

    map->height = get_map_height(filename);  // Höhe VOR allocate_map() setzen!
    if (map->height == 0)
        return (NULL);

    map->grid = malloc(sizeof(int *) * map->height);  // Sicherstellen, dass grid existiert!
    if (!map->grid)
    {
        perror("Memory allocation failed for grid");
        return (free(map), NULL);
    }

    line = get_next_line(fd);  // Erste Zeile holen
    if (!line)
    {
        free(map->grid);
        free(map);
        close(fd);
        return (NULL);
    }

    map->width = get_map_width(line);  // Breite setzen

    while (i < map->height)
    {
        if (!line)  // Falls get_next_line() fehlschlägt
            break;

        map->grid[i] = get_column(line, &map->width);
        free(line);

        if (!map->grid[i])  // Falls get_column() fehlschlägt
        {
            free_map(map);
            close(fd);
            return (NULL);
        }

        line = get_next_line(fd);
        i++;
    }

    close(fd);
    return (map);
}
