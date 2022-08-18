/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:43:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/18 15:12:07 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

double	calculate_ray_distance(t_point player_pos, t_point wall_pos)
{
	return (sqrt((player_pos.x - wall_pos.x) * (player_pos.x - wall_pos.x) + (player_pos.y - wall_pos.y) * (player_pos.y - wall_pos.y)));
}

int	draw_wall(t_raycast *raycast, int x_start, double wall_height)
{
	double y_start;
	double wall_height_half;

	wall_height_half = wall_height / 2;
	y_start = raycast->centre_height;
	if (wall_height > WIN_HEIGHT)
	{
		drawline(raycast->data, x_start, 0, x_start, WIN_HEIGHT / 2 - 1);
		drawline(raycast->data, x_start, y_start, x_start, WIN_HEIGHT / 2 - 1);
	}
	else
	{
		drawline(raycast->data, x_start, y_start, x_start, (WIN_HEIGHT / 2) - wall_height_half - 1);
		drawline(raycast->data, x_start, y_start, x_start, (WIN_HEIGHT / 2) + wall_height_half);
	}
	return (1);
}