/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:15:32 by mknoll            #+#    #+#             */
/*   Updated: 2025/01/31 15:27:33 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

typedef struct s_map
{
	int	**grid;
	int	width;
	int	height;
}	t_map;
#endif