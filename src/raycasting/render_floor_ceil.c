/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:29:16 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/21 20:18:20 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
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
