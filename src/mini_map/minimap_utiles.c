/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:39:34 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/27 20:38:01 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void normlise_DX_DY(t_raycast *data, t_rect *rectangle)
{
    if (data->Dx == 0)
        ;
    else if (data->Dx < 0)
        rectangle->x += fabs(data->Dx);
    if (data->Dx > 0)
        rectangle->x -= data->Dx;
    if (data->Dy == 0)
        ;
    else if (data->Dy < 0)
        rectangle->y += fabs(data->Dy) ;
    if (data->Dy > 0)
        rectangle->y -= data->Dy;
}

void    get_scalling_unites(t_raycast *raycast)
{
   raycast->Dx = (raycast->player->minimap_pos.x) - MIMPW_CENTER;
   raycast->Dy = (raycast->player->minimap_pos.y) - MIMPH_CENTER;
}

void set_minimap_field(t_raycast *raycast)
{
    int i;
	int	j;

	i = 0;
	while (i <= MINI_HEIGHT)
	{
		j = 0;
		while(j <= MINI_WIDTH)
		{
            if (i == 0 || i == MINI_HEIGHT || j == 0 || j == MINI_WIDTH)
                my_mlx_put_pixel(raycast, j, i, 0xFF0000);
			else if (i < MINI_HEIGHT && j < MINI_WIDTH)
                ;
				//  my_mlx_put_pixel(raycast, j, i, 0x0000000);
			j++;
		}
		i++;
	}
}