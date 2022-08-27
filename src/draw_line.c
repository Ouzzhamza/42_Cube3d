/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:46:59 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/27 19:38:37 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"

void	drawline(t_raycast *data, int x0, int y0, int x1, int y1)
{
	t_bresn	bre;

	bre.dx = abs(x1 - x0);
	if (x0 < x1)
		bre.sx = 1;
	else
		bre.sx = -1;
	bre.dy = -abs(y1 - y0);
	if (y0 < y1)
		bre.sy = 1;
	else
		bre.sy = -1;
	bre.err = bre.dx + bre.dy;
	while (1)
	{
		my_mlx_put_pixel(data, x0, y0, 0x00FF00);
		bre.e2 = 2 * bre.err;
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
