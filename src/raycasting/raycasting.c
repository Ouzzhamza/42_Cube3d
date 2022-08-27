/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:42:39 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/26 18:54:19 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

t_point	get_horiz_inters_point(t_raycast *raycast, double angle)
{
	t_point	inters;
	t_point	delta;
	t_point	grid;

	inters = first_intersec_horiz(raycast, angle);
	delta = xy_steps_horiz(angle);
	while (inters.x >= 0 && inters.x < raycast->map->map_width
		&& inters.y >= 0 && inters.y < raycast->map->map_height)
	{
		if (ft_is_ray_up(angle))
			grid.y = (inters.y - 1);
		else
			grid.y = inters.y;
		grid.x = inters.x;
		if (raycast->map->map[(int)grid.y][(int)grid.x] == '1')
			return ((t_point){inters.x, inters.y});
		inters.x += delta.x;
		inters.y += delta.y;
	}
	return ((t_point){1e9, 1e9});
}

t_point	get_vertic_inters_point(t_raycast *raycast, double angle)
{
	t_point	inters;
	t_point	delta;
	t_point	grid;

	inters = first_intersec_vertic(raycast, angle);
	delta = xy_steps_vertic(angle);
	while (inters.x >= 0 && inters.x < raycast->map->map_width
		&& inters.y >= 0 && inters.y < raycast->map->map_height)
	{
		if (!ft_is_ray_right(angle))
			grid.x = (inters.x - 1);
		else
			grid.x = (inters.x);
		grid.y = inters.y;
		if (raycast->map->map[(int)grid.y][(int)grid.x] == '1')
			return ((t_point){inters.x, inters.y});
		inters.x += delta.x;
		inters.y += delta.y;
	}
	return ((t_point){1e9, 1e9});
}

double	valid_inters(t_raycast *raycast, t_point ray_horizontal, t_point ray_vertical, double angle)
{
	double	horiz_dist;
	double	vertic_dist;

	if (ray_horizontal.x != 1e9 && ray_horizontal.y != 1e9)
	{
		horiz_dist = calculate_ray_distance(raycast->player->map_pos, ray_horizontal);
		if (ray_vertical.x != 1e9 && ray_vertical.y != 1e9)
		{
			vertic_dist = calculate_ray_distance(raycast->player->map_pos, ray_vertical);
			if (horiz_dist < vertic_dist)
			{
				raycast->inters_type = 0;
				return (horiz_dist * cos(raycast->player->angle - angle));
			}
			raycast->inters_type = 1;
			return (vertic_dist * cos(raycast->player->angle - angle));
		}
		raycast->inters_type = 0;
		return (horiz_dist * cos(raycast->player->angle - angle));
	}
	vertic_dist = calculate_ray_distance(raycast->player->map_pos, ray_vertical);
	raycast->inters_type = 1;
	return (vertic_dist * cos(raycast->player->angle - angle));
}

int	ray_casting(t_raycast *raycast)
{
	int		i;
	double	dist;
	double	ray_angle;
	t_point	horiz_ray;
	t_point	vertic_ray;

	i = 0;
	ray_angle = raycast->player->angle - (M_PI / 6);
	while (i < WIN_WIDTH)
	{
		ray_angle = normlize_angle(ray_angle);
		horiz_ray = get_horiz_inters_point(raycast, ray_angle);
		vertic_ray = get_vertic_inters_point(raycast, ray_angle);
		dist = valid_inters(raycast, horiz_ray, vertic_ray, ray_angle);
		raycast->wall_height = calculate_wall_projection(dist);
		if (raycast->inters_type == 0)
		{
			draw_proj_wall(raycast, i, get_texture_by_direc(raycast, ray_angle), horiz_ray);
			raycast->x[i] = horiz_ray.x;
			raycast->y[i] = horiz_ray.y;
		}
		else
		{
			draw_proj_wall(raycast, i, get_texture_by_direc(raycast, ray_angle), vertic_ray);
			raycast->x[i] = vertic_ray.x;
			raycast->y[i] = vertic_ray.y;
		}
		ray_angle += raycast->increment_angle;
		i++;
	}
	return (1);
}
