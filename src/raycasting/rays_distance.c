/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:43:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/21 11:20:25 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

double	calculate_ray_distance(t_point player_pos, t_point wall_pos)
{
	return (sqrt(pow(player_pos.x - wall_pos.x, 2) + pow(player_pos.y - wall_pos.y, 2)));
}

int	draw_wall(t_raycast *raycast, int x_start, double wall_height)
{
	double y_start;
	double wall_height_half;

	wall_height_half = wall_height / 2;
	y_start = raycast->centre_height;
	if (wall_height >= WIN_HEIGHT)
		drawline(raycast->data, x_start, 0, x_start, WIN_HEIGHT - 1);
	else
	{
		drawline(raycast->data, x_start, y_start, x_start, raycast->centre_height - wall_height_half);
		drawline(raycast->data, x_start, y_start, x_start, raycast->centre_height + wall_height_half);
	}
	return (1);
}