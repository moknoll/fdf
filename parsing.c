/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:10 by mknoll            #+#    #+#             */
/*   Updated: 2025/01/31 16:17:32 by mknoll           ###   ########.fr       */
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
	printf("%d", width);
	return (width);
}

int	get_map_height(const char filename)
{
	int		fd;
	t_map	*map_data;
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_data = malloc(sizeof(map_data));
	if (!map_data)
		perror("malloc failed");
	map_data->height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map_data->height == 0)
			map_data->width = get_map_width(line);	//if this is the first call check for width 
		map_data->height++;
		free(line);
	}
	return (map_data->height);
}

// t_map	*parse_map(const char *filename)
// {
// }

int main()
{
	char *datei;

	datei = "test.txt";

	get_map_height(datei);
}
