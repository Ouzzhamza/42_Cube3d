/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/22 08:56:21 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
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
	int i;
	int j;
	
	if (data->data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			my_mlx_put_pixel(data, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_raycast *data, int x, int y, int color)
{
	t_rect rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = CUB_SIZE / 2;
	rectangle.height = CUB_SIZE / 2;
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
	render_rect(data, rectangle);
	return (0);
}

void	draw_minimap(t_raycast *data, char **map)
{
	int i;
	int	j;
	int	x_start;
	int y_start;

	i = 0;
	while (map[i])
	{
		j = 0;
		y_start = i * (CUB_SIZE / 2);
		while (map[i][j])
		{
			x_start = j * (CUB_SIZE / 2);
			if (map[i][j] == '0')
			{
				render(data, x_start, y_start, 0xFFFFFF);
			}
			else if (map[i][j] == '1')
				render(data, x_start, y_start, 0xFF0000);
			else if (map[i][j] != ' ')
			{
				map[i][j] = '0';
				render(data, x_start, y_start, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}
