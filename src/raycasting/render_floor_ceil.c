/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:29:16 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 17:06:47 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs.h"

void	render_image_color(t_raycast *raycast, int color, int y_start)
{
	int	i;
	int	j;

	i = y_start;
	while (i < WIN_HEIGHT / 2 + y_start)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_put_pixel(raycast, j, i, color);
			j++;
		}
		i++;
	}
}
