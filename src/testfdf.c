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

void	put_pixel(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x * (data->bpp / 8));

	*(unsigned int *)dst = color;
}

int	render(t_mlx_data *data)
{
	int x, y;

	for (y = 0; y < data->map->height; y++)
	{
		for (x = 0; x < data->map->width; x++)
		{
			int value = data->map->grid[y][x]; // Wert aus der Map holen
			int color = 0x00FF00; // Grün als Standardfarbe

			// Farben basierend auf Höhenwert setzen
			if (value > 5)
				color = 0xFF0000; // Rot für hohe Werte
			else if (value < 3)
				color = 0x0000FF; // Blau für niedrige Werte

			// Punkt zeichnen, skaliere x und y für bessere Darstellung
			put_pixel(data, x * 10, y * 10, color);
		}
	}

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}


int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_map		*map;

	if (argc != 2)
	{
		printf("Usage: %s <mapfile>\n", argv[0]);
		return (1);
	}

	map = get_map(NULL, argv[1]);  // Map aus Datei einlesen
	if (!map)
	{
		printf("Fehler: Konnte die Map nicht laden.\n");
		return (1);
	}

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDGHT,
			WINDOW_HEIGHT, "My Window");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.win_ptr);
		return (1);
	}

	data.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDGHT, WINDOW_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.line_length, &data.endian);

	data.map = map; // Speichere Map in struct

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);

	free_map(map);
}
