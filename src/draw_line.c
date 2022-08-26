#include "../includes/structs.h"
#include "../includes/cube3d.h"

void    drawline(t_raycast *data, int x0, int y0, int x1, int y1)
{
    t_bresn bre;

    bre.dx = abs(x1 - x0);
    bre.sx = x0<x1 ? 1 : -1;
    bre.dy = -abs(y1 - y0);
    bre.sy = y0<y1 ? 1 : -1;
    bre.err = bre.dx + bre.dy;
    while (1)
    {
        my_mlx_put_pixel(data, x0, y0, 103);
        bre.e2 = 2*bre.err;
        if (bre.e2 >= bre.dy)
        {
            if (x0 == x1)
                break ;
            bre.err += bre.dy;
            x0 += bre.sx;
        }
        if (bre.e2 <= bre.dx)
        {
            if (y0 == y1)
                break ;
            bre.err += bre.dx;
            y0 += bre.sy;
        }
    }
}
