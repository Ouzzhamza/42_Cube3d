/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/27 19:48:35 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
	normlise_DX_DY(data, &rectangle);
	render_rect(data, rectangle);
	return (0);
}

int	render_player(t_raycast *data, int x, int y, int color)
{
	t_rect	rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y; 
	rectangle.width = CUB_SIZE / 3;
	rectangle.height = CUB_SIZE / 3;
	normlise_DX_DY(data, &rectangle);
	render_rect(data, rectangle);
	return (0);
}

void draw_minimap(t_raycast *data, char **map)
{
	set_minimap_field(data);
	get_scalling_unites(data);
	int	i;
	int	j;
	int	x_start;
	int	y_start;

	i = 0;
	while (map[i])
	{
		j = 0;
		y_start = i * (CUB_SIZE);
		while (map[i][j])
		{
			x_start = j * (CUB_SIZE);
			if (map[i][j] == '0' || map[i][j] == ' ')
					;
			else if (map[i][j] == '1')
				render(data, x_start, y_start, 0x808080);
			else if (map[i][j] != ' ')
				 map[i][j] = '0';
			j++;
		}
		i++;
	}
}
