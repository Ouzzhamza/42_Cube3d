/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:43:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/25 10:49:49 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

double	calculate_ray_distance(t_point player_pos, t_point wall_pos)
{
	return (sqrt(pow((player_pos.x - wall_pos.x), 2) + pow((player_pos.y - wall_pos.y), 2)));
}

void	draw_proj_wall(t_raycast *raycast, int x_start, double wall_height, t_point inters)
{
	double		x_offset;
	double		y_offset;
	int			draw_start;
	int			draw_end;
	int			y;
	int			color;
	int			dist_fromTop;

	draw_start = raycast->centre_height - (wall_height / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = raycast->centre_height + (wall_height / 2);
	if (draw_end > WIN_HEIGHT)
		draw_end = WIN_HEIGHT;
	if (raycast->inters_type == 0)
	{
		x_offset = inters.x - (int)(inters.x); 
		x_offset = x_offset * raycast->textures->width;
	}
	else
	{
		x_offset = inters.y - (int)inters.y;
		x_offset = x_offset * raycast->textures->width;
	}
	y = draw_start;
	while (y < draw_end)
	{
		dist_fromTop = y + (wall_height / 2) - (WIN_HEIGHT / 2);
		y_offset = dist_fromTop * ((double)(raycast->textures->height) / wall_height);
		color = raycast->textures->addr[raycast->textures->width * (int)y_offset + (int)x_offset];
		raycast->data->img.addr[y * WIN_WIDTH + x_start] = color;
		y++;
	}
}
