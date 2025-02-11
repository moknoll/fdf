/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:15:32 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/11 13:46:30 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
typedef struct s_map
{
	int	**grid;
	int	width;
	int	height;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_map	*map;
}	t_mlx_data;

void free_map(t_map *map);

int	*get_column(char *line, int *width);
int	fd_open(const char *filename);
t_map	*get_map(t_map *map, const char *filename);
t_map	*allocate_map(t_map *map);

void	free_tab(char **arr);
int	get_map_width(char *line);
int	get_map_height(const char *filename);


#endif