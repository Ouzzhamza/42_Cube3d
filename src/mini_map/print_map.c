/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 17:06:19 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_put_pixel(t_raycast *raycast, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		raycast->data->img.addr[y * WIN_WIDTH + x] = color;
	}
}

int	render_rect(t_raycast *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			if ((j != 0 && i != 0) && (j < 349 && i < 149))
				my_mlx_put_pixel(data, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_raycast *data, int x, int y, int color)
{
	t_rect	rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = CUB_SIZE;
	rectangle.height = CUB_SIZE;
	normlise_dx_dy(data, &rectangle);
	render_rect(data, rectangle);
	return (0);
}

int	render_player(t_raycast *data, int x, int y, int color)
{
	t_rect	rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = CUB_SIZE / 8;
	rectangle.height = CUB_SIZE / 8;
	normlise_dx_dy(data, &rectangle);
	render_rect(data, rectangle);
	my_mlx_put_pixel(data, rectangle.x, rectangle.y, 0x000000);
	trace_rays(data, &rectangle);
	return (0);
}

void	draw_minimap(t_raycast *data, char **map)
{
	set_minimap_field(data);
	get_scalling_unites(data);
	draw_minimap_walls(data, map);
	render_player(data, data->player->minimap_pos.x, \
	data->player->minimap_pos.y, 0);
}
