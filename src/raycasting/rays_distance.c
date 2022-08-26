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

void	draw_proj_wall(t_raycast *raycast, int x_start, t_img *texture, t_point inters)
{
	t_proj	proj;
	int		y;

	proj.draw_start = raycast->centre_height - (raycast->wall_height / 2);
	if (proj.draw_start < 0)
		proj.draw_start = 0;
	proj.draw_end = raycast->centre_height + (raycast->wall_height / 2);
	if (proj.draw_end > WIN_HEIGHT)
		proj.draw_end = WIN_HEIGHT;
	if (raycast->inters_type == 0)
	{
		proj.x_offset = inters.x - (int)(inters.x); 
		proj.x_offset = proj.x_offset * texture->width;
	}
	else
	{
		proj.x_offset = inters.y - (int)inters.y;
		proj.x_offset = proj.x_offset * texture->width;
	}
	y = proj.draw_start;
	while (y < proj.draw_end)
	{
		proj.dist_from_top = y + (raycast->wall_height / 2) - (WIN_HEIGHT / 2);
		proj.y_offset = proj.dist_from_top * ((double)(texture->height) / raycast->wall_height);
		proj.color = texture->addr[texture->width * (int)proj.y_offset + (int)proj.x_offset];
		raycast->data->img.addr[y * WIN_WIDTH + x_start] = proj.color;
		y++;
	}
	// printf("angle: %f-- ray_index: %d\n", raycast->player->angle, x_start);
}
