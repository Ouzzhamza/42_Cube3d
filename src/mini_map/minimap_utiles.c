/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:39:34 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/28 08:36:56 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	normlise_dx_dy(t_raycast *data, t_rect *rectangle)
{
	if (data->dx == 0)
		;
	else if (data->dx < 0)
		rectangle->x += fabs(data->dx);
	if (data->dx > 0)
		rectangle->x -= data->dx;
	if (data->dy == 0)
		;
	else if (data->dy < 0)
		rectangle->y += fabs(data->dy);
	if (data->dy > 0)
		rectangle->y -= data->dy;
}

void	get_scalling_unites(t_raycast *raycast)
{
	raycast->dx = (raycast->player->minimap_pos.x) - MIMPW_CENTER;
	raycast->dy = (raycast->player->minimap_pos.y) - MIMPH_CENTER;
}

void	set_minimap_field(t_raycast *raycast)
{
	int	i;
	int	j;

	i = 0;
	while (i <= MINI_HEIGHT)
	{
		j = 0;
		while (j <= MINI_WIDTH)
		{
			if (i == 0 || i == MINI_HEIGHT || j == 0 || j == MINI_WIDTH)
				my_mlx_put_pixel(raycast, j, i, 0xFF0000);
			else if (i < MINI_HEIGHT && j < MINI_WIDTH)
				;
			j++;
		}
		i++;
	}
}
