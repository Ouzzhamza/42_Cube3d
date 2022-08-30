/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:39:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 17:10:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d.h"

double	calculate_wall_projection(double dist_wall)
{
	return (WIN_HEIGHT / (dist_wall * 2));
}

bool	ft_is_ray_up(double angle)
{
	if (angle > M_PI && angle < (2 * M_PI))
		return (true);
	return (false);
}

bool	ft_is_ray_right(double angle)
{
	if ((angle < M_PI / 2) || (angle > 1.5 * M_PI))
		return (true);
	return (false);
}

double	normlize_angle(double angle)
{
	if (angle >= 0)
		angle = fmod(angle, (2 * M_PI));
	else
		angle += (2 * M_PI);
	return (angle);
}
