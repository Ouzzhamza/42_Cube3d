/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:42:39 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/17 12:34:59 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

t_point	get_horiz_inters_point(t_raycast *raycast, double angle)
{
	t_point	inters;
	t_point	delta;
	t_point	grid;
	bool wall_interct;

	wall_interct = false;
	inters = first_intersec_horiz(raycast, angle);
	delta = xy_steps_horiz(angle);
	while (inters.x >= 0 && inters.x < (CUB_SIZE * raycast->map->map_width) && inters.y >= 0 && inters.y < (raycast->map->map_height * CUB_SIZE))
	{
		grid.x = inters.x / CUB_SIZE;
		grid.y = inters.y / CUB_SIZE;
		// printf("Horizontal:Here1\n");
		// printf("%f ---- %f\n", grid.x, grid.y);
		if (raycast->map->map[(int)grid.y][(int)grid.x] == '1')
		{
			// printf("Horizontal:Here2\n");
			wall_interct = true;
			grid.x = inters.x;
			grid.y = inters.y;
			break ;
		}
		inters.x += delta.x;
		inters.y += delta.y;
	}
	if (!wall_interct)
	{
		grid.x = 2147483647;
		grid.y = 2147483647;
	}
	return (grid);
}

t_point	get_vertic_inters_point(t_raycast *raycast, double angle)
{
	t_point	inters;
	t_point	delta;
	t_point	grid;
	bool wall_interct;

	wall_interct = false;
	inters = first_intersec_vertic(raycast, angle);
	delta = xy_steps_vertic(angle);
	while (inters.x >= 0 && inters.x < (CUB_SIZE * raycast->map->map_width) - 1 && inters.y >= 0 && inters.y < (raycast->map->map_height * CUB_SIZE) - 1)
	{
		grid.x = inters.x / CUB_SIZE;
		grid.y = inters.y / CUB_SIZE;
		// printf("Vertical:Here1\n");
		// printf("%f ---- %f\n", grid.x, grid.y);
		if (raycast->map->map[(int)grid.y][(int)grid.x] == '1')
		{
			// printf("Vertical:Here2\n");
			wall_interct = true;
			grid.x = inters.x;
			grid.y = inters.y;
			break ;
		}
		inters.x += delta.x;
		inters.y += delta.y;
	}
	if (!wall_interct)
	{
		grid.x = 2147483647;
		grid.y = 2147483647;
	}
	return (grid);
}

t_point	valid_inters(t_raycast *raycast, t_point ray_horizontal, t_point ray_vertical)
{
	double	horiz_dist;
	double	vertic_dist;

	if (ray_horizontal.x != 2147483647 || ray_horizontal.y != 2147483647)
	{
		if (ray_vertical.x != 2147483647 || ray_vertical.y != 2147483647)
		{
			horiz_dist = calculate_ray_distance(raycast->player->map_pos, ray_horizontal);
			vertic_dist = calculate_ray_distance(raycast->player->map_pos, ray_vertical);
			if (horiz_dist < vertic_dist)
				return (ray_horizontal);
			return (ray_vertical);
		}
		else
			return (ray_horizontal);
	}
	else if (ray_vertical.x != 2147483647 || ray_vertical.y != 2147483647)
		return (ray_vertical);
	return ((t_point) {2147483647, 2147483647});
}

int	ray_casting(t_raycast *raycast)
{
	int		i;
	double	ray_angle;
	t_point	horiz_ray;
	t_point	vertic_ray;
	t_point	ray;
	
	i = 0;
	ray_angle = raycast->player->angle - (M_PI / 6);
	while (i < WIN_WIDTH)
	{
		ray_angle = normlize_angle(ray_angle);
		horiz_ray = get_horiz_inters_point(raycast, ray_angle);
		vertic_ray = get_vertic_inters_point(raycast, ray_angle);
		ray = valid_inters(raycast, horiz_ray, vertic_ray);
		if (ray.x == 2147483647)
		{
			ray_angle += raycast->increment_angle;
			i++;
			continue ;
		}
		else
		{
			raycast->rays[i] = calculate_ray_distance(raycast->player->map_pos, ray);
			raycast->wall_proj[i] = calculate_wall_projection(raycast, raycast->rays[i]);
			// printf("Distans: %d -- %f\n",i, raycast->wall_proj[i]);
			draw_wall(raycast, i, raycast->wall_proj[i]);
			// printf("Here\n");
		}
		
			// drawline(raycast->data, raycast->player->map_pos.x, raycast->player->map_pos.y, ray.x, ray.y);
		ray_angle += raycast->increment_angle;
		i++;
	}
	return (1);
}
