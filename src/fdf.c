/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:24:44 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/06 10:54:53 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDGHT 1920

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

int	put_pixel(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x * (data->bpp / 8));

	*(unsigned int *)dst = color;
}

int	render(t_mlx_data *data)
{
	put_pixel(data, 400, 800, 0x00FF00);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT,
			WINDOW_WIDGHT, "My Window");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.win_ptr);
		return (1);
	}

	data.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDGHT);
	data.img_addr = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.line_length, &data.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}