/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:10 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/13 12:54:05 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int *get_column(char *line, int *width)
{
    char **result;
    int *numbers;
    int i;

    i = 0;
    result = ft_split(line, ' ');
    if (!result)
        return (NULL);
    numbers = malloc(sizeof(int) * (*width));
    if (!numbers)
    {
        free_tab(result);  // Vergewissere dich, dass result hier freigegeben wird
        return (NULL);
    }

    while (i < *width)
    {
        if (!result[i])
        {
            free_tab(result);  // Vergewissere dich, dass result hier freigegeben wird
            free(numbers);
            return (NULL);
        }

        numbers[i] = ft_atoi(result[i]);
        free(result[i]);
        i++;
    }
    free(result);  // Vergewissere dich, dass result hier freigegeben wird
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
        map->grid[i] = get_column(line, &map->width);  // Zuweisung der Zeilen
        free(line);  // Hier freigeben, nachdem wir es benutzt haben
        if (!map->grid[i])  // Falls get_column() fehlschlägt
            return (free_map(map), NULL);
        line = get_next_line(fd);
        i++;
    }

    close(fd);  // Datei schließen

    return (map);  // Rückgabe der Map
}


// int main(int argc, char **argv)
// {
//     t_map *map;

//     if (argc != 2)
//     {
//         printf("Usage: %s <mapfile>\n", argv[0]);
//         return 1;
//     }

//     // Aufruf der get_map-Funktion, um die Map zu laden
//     map = get_map(NULL, argv[1]);

//     if (!map)
//     {
//         printf("Error: Could not load map\n");
//         return 1;
//     }

//     // Gebe die Map und den zugehörigen Speicher frei
//     free_map(map);

//     return 0;
// }
