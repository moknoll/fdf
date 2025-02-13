#include "fdf.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		close_window(data);
	}

	return (0);
}

void free_image(t_mlx_data *data)
{
    if (data->img_ptr)
    {
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);  // Bild freigeben
        data->img_ptr = NULL;  // Null setzen, um versehentliche Zugriffe zu vermeiden
    }
}


int close_window(t_mlx_data *data)
{
    if (data->img_ptr)
    {
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);  // Zerstöre das Bild
        data->img_ptr = NULL;  // Null setzen, um versehentliche Zugriffe zu vermeiden
    }
    if (data->win_ptr)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);  // Zerstöre das Fenster
    }
    if (data->mlx_ptr)
    {
        mlx_destroy_display(data->mlx_ptr);  // Zerstöre die Anzeige
        free(data->mlx_ptr);  // Gib den Speicher für die Display-Verbindung frei
    }
    exit(0);  // Beende das Programm
    return (0);
}



void	put_pixel(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x * (data->bpp / 8));

	*(unsigned int *)dst = color;
}

int render(t_mlx_data *data)
{
    int x, y;
    int offsetx, offsety;
    int iso_x, iso_y;
    offsetx = (WINDOW_WIDTH - (data->map->width * 10)) / 2;
    offsety = (WINDOW_HEIGHT - (data->map->height * 10)) / 2;

    // Farben und Linien zeichnen
    for (y = 0; y < data->map->height; y++)
    {
        for (x = 0; x < data->map->width; x++)
        {
            int value = data->map->grid[y][x]; // Wert aus der Map holen
            int color = gradient(0, 10, value);
            // Koordinaten für die Isometrische Projektion berechnen
            iso_x = x * 10;  // Skalierung
            iso_y = y * 10;  // Skalierung
            isometric_projection(&iso_x, &iso_y, value);  // Hier wird der Punkt projiziert

            // Verschiebe den Punkt, um ihn im Fenster richtig darzustellen
            iso_x += offsetx;
            iso_y += offsety;

            // Punkt zeichnen
            put_pixel(data, iso_x, iso_y, color);

            // Horizontale Linie zwischen benachbarten Punkten
            if (x < data->map->width - 1)
            {
                int next_iso_x, next_iso_y;
                next_iso_x = (x + 1) * 10;
                next_iso_y = y * 10;
                isometric_projection(&next_iso_x, &next_iso_y, data->map->grid[y][x + 1]);
                next_iso_x += offsetx;
                next_iso_y += offsety;
                draw_line_bresenham(data, iso_x, iso_y, next_iso_x, next_iso_y, color);
            }

            // Vertikale Linie zwischen benachbarten Punkten
            if (y < data->map->height - 1)
            {
                int next_iso_x, next_iso_y;
                next_iso_x = x * 10;
                next_iso_y = (y + 1) * 10;
                isometric_projection(&next_iso_x, &next_iso_y, data->map->grid[y + 1][x]);
                next_iso_x += offsetx;
                next_iso_y += offsety;
                draw_line_bresenham(data, iso_x, iso_y, next_iso_x, next_iso_y, color);
            }
        }
    }

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
    return (0);
}



int main(int argc, char **argv)
{
    t_mlx_data data;
    t_map *map;

    if (argc != 2)
    {
        printf("Usage: %s <mapfile>\n", argv[0]);
        return (1);
    }

    map = get_map(NULL, argv[1]); // Map aus Datei einlesen
    if (!map)
    {
        printf("Fehler: Konnte die Map nicht laden.\n");
        return (1);
    }

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);

    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
    if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.win_ptr);
        return (1);
    }

    data.img_ptr = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    data.img_addr = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.line_length, &data.endian);
    data.map = map; // Speichere Map in struct

    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_key_hook(data.win_ptr, handle_input, &data);
    mlx_hook(data.win_ptr, 17, 0, (int (*)(void *))close_window, &data);

    mlx_loop(data.mlx_ptr);

    free_map(map); // Map freigeben
    return (0);
}

