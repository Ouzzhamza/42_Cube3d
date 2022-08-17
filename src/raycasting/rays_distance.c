/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:43:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/17 12:37:33 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

double	calculate_ray_distance(t_point player_pos, t_point wall_pos)
{
	double	distance;

	distance = sqrt(pow((player_pos.x - wall_pos.x), 2) + pow((player_pos.y - wall_pos.y), 2));
	// distance = fabs((player_pos.x - wall_pos.x) * acos(angle));
	return(distance);
}

int	draw_wall(t_raycast *raycast, int x_start, double wall_height)
{
	double y_start;
	double i;
	double wall_height_half;

	wall_height_half = wall_height / 2;
	y_start = raycast->centre_height;
	i = 0;
	while ((i + wall_height_half) < wall_height && (i + wall_height_half) < WIN_HEIGHT)
	{
		// printf("%d-----%f-----wall_height:%f\n",x_start, (y_start + i), wall_height);
		drawline(raycast->data, x_start, y_start, x_start, (y_start + i));
		i++;
	}
	i = 0;
	while ((wall_height_half - i) > 0 && (wall_height_half - i) < WIN_HEIGHT)
	{
		drawline(raycast->data, x_start, y_start, x_start, (y_start - i));
		i++;
	}
	return (1);
}