/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:39:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/24 15:28:05 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/cube3d.h"

double	calculate_wall_projection(t_raycast *raycast, double dist_wall)
{
	return (raycast->height_proj / dist_wall);
}

void	intersection_cordinate(t_raycast *raycast, t_point *horiz_ray, \
		 t_point *vertic_ray, int i)
{
	if (raycast->inters_type == 0)
	{
		raycast->x[i] = horiz_ray->x;
		raycast->y[i] = horiz_ray->y;
	}
	else if (raycast->inters_type == 1)
	{
		raycast->x[i] = vertic_ray->x;
		raycast->y[i] = vertic_ray->y;
	}
}