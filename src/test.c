#include "fdf.h"

// void print_map(t_map *map)
// {
//     if (!map)
//     {
//         printf("Fehler: Map konnte nicht geladen werden.\n");
//         return;
//     }

//     printf("Map Größe: %dx%d\n", map->width, map->height);

//     for (int y = 0; y < map->height; y++)
//     {
//         for (int x = 0; x < map->width; x++)
//         {
//             printf("%d ", map->grid[y][x]);
//         }
//         printf("\n");
//     }
// }

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


// int main(int argc, char **argv)
// {
// 	t_map *map = malloc(sizeof(t_map));
// 	if (!map)
// 	{
//     	printf("Memory allocation failed!\n");
//     	return 1;
// 	}
//     if (argc != 2)
//     {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return 1;
//     }

// 	if (get_map(map, argv[1]) == NULL)
// 	{
// 		printf("Fehler: Konnte die Map nicht laden.\n");
// 		free(map);
// 		return 1;
// 	}

//     print_map(map);
//     free_map(map);

//     return 0;
// }