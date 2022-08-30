/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_steps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:23:31 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 17:06:33 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs.h"

t_point	first_intersec_horiz(t_raycast *raycast, double angle)
{
	double	x_intersection;
	double	y_intersection;
	t_point	grid;

	y_intersection = (int)(raycast->player->map_pos.y);
	if (!ft_is_ray_up(angle))
		y_intersection += 1;
	x_intersection = raycast->player->map_pos.x + \
	(y_intersection - raycast->player->map_pos.y) / tan(angle);
	grid.x = x_intersection;
	grid.y = y_intersection;
	return (grid);
}

t_point	xy_steps_horiz(double angle)
{
	t_point	delta;

	delta.y = 1;
	if (ft_is_ray_up(angle))
		delta.y *= -1;
	delta.x = 1 / tan(angle);
	if (!ft_is_ray_right(angle) && delta.x > 0)
		delta.x *= -1;
	if (ft_is_ray_right(angle) && delta.x < 0)
		delta.x *= -1;
	return (delta);
}

t_point	first_intersec_vertic(t_raycast *raycast, double angle)
{
	double	x_intersection;
	double	y_intersection;
	t_point	grid;

	x_intersection = (int)(raycast->player->map_pos.x);
	if (ft_is_ray_right(angle))
		x_intersection += 1;
	y_intersection = raycast->player->map_pos.y + \
	(x_intersection - raycast->player->map_pos.x) * tan(angle);
	grid.x = x_intersection;
	grid.y = y_intersection;
	return (grid);
}

t_point	xy_steps_vertic(double angle)
{
	t_point	delta;

	delta.x = 1;
	if (!ft_is_ray_right(angle))
		delta.x *= -1;
	delta.y = 1 * tan(angle);
	if (ft_is_ray_up(angle) && delta.y > 0)
		delta.y *= -1;
	if (!ft_is_ray_up(angle) && delta.y < 0)
		delta.y *= -1;
	return (delta);
}
