#include "../includes/structs.h"
#include "../includes/cube3d.h"

void    drawline(t_raycast *data, int x0, int y0, int x1, int y1)
{
    int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int e2;

    dx = abs(x1 - x0);
    sx = x0<x1 ? 1 : -1;
    dy = -abs(y1 - y0);
    sy = y0<y1 ? 1 : -1;
    err = dx + dy;
    while (1)
    {
        my_mlx_put_pixel(data, x0, y0, 103);
        e2 = 2*err;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break ;
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break ;
            err += dx;
            y0 += sy;
        }
    }
}
