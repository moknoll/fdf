/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:13:56 by mknoll            #+#    #+#             */
/*   Updated: 2025/02/13 12:49:09 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric_projection(int *x, int *y, int z)
{
    int tmp_x;
    double angle = 0.523599; // 30° in Radians

    tmp_x = *x;
    *x = (tmp_x - *y) * cos(angle);
    *y = (tmp_x + *y) * sin(angle) - z;
}


void draw_line_bresenham(t_mlx_data *data, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        put_pixel(data, x1, y1, color);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

// gradient

int gradient(int min_val, int max_val, int value)
{
    float ratio = (float)(value - min_val) / (max_val - min_val);

    int red   = (int)((1.0 - ratio) * 0xF0 + ratio * 0x5A); // Gold → Hellblau
    int green = (int)((1.0 - ratio) * 0xC9 + ratio * 0xC9);
    int blue  = (int)((1.0 - ratio) * 0x1D + ratio * 0xED);

    return (red << 16) | (green << 8) | blue;
}
