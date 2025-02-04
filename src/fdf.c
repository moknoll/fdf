/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:24:44 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/04 12:54:16 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

#define HEIGHT 500
#define WIDGHT 500

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data-> mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed \n\n", keysym);
	return (0);
}


int	render(t_mlx_data *data)
{
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);

	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDGHT, "My Window");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.win_ptr);
		return (1);
	}
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}