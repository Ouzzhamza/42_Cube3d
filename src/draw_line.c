/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:46:59 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/28 08:34:55 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"

void	drawline(t_raycast *data, t_intpo p0, t_intpo p1)
{
	t_bresn	bre;

	bre.dx = abs(p1.x - p0.x);
	if (p0.x < p1.x)
		bre.sx = 1;
	else
		bre.sx = -1;
	bre.dy = -abs(p1.y - p0.y);
	if (p0.y < p1.y)
		bre.sy = 1;
	else
		bre.sy = -1;
	bre.err = bre.dx + bre.dy;
	while (1)
	{
		my_mlx_put_pixel(data, p0.x, p0.y, 0x0FF00);
		bre.e2 = 2 * bre.err;
		if (bre.e2 >= bre.dy)
		{
			if (p0.x == p1.x)
				break ;
			bre.err += bre.dy;
			p0.x += bre.sx;
		}
		if (bre.e2 <= bre.dx)
		{
			if (p0.y == p1.y)
				break ;
			bre.err += bre.dx;
			p0.y += bre.sy;
		}
	}
}
