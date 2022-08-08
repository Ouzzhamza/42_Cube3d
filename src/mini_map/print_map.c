/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/08 13:36:15 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}

int	render_rect(t_data *data, t_rect rect)
{
	int i;
	int j;
	
	if (data->win_ptr == NULL)
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

int	render(t_data *data, int x, int y, int color)
{
	t_rect rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = 64;
	rectangle.height = 64;
	render_rect(data, rectangle);
	return (0);
}

int	render_player(t_data *data, int x, int y, int color)
{
	t_rect	rectangle;

	rectangle.color = color;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = 16;
	rectangle.height = 16;
	render_rect(data, rectangle);
	return (0);
}

void	draw_minimap(t_data *data, char **map)
{
	int i;
	int	j;
	int x_start;
	int y_start;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			x_start = j * CUB_SIZE;
			y_start = i * CUB_SIZE;
			if (map[i][j] == ' ')
			{
				render(data, x_start, y_start, 0x000000);
			}
			else if (map[i][j] == '0')
			{
				render(data, x_start, y_start, 0xFFFFFF);
			}
			else if (map[i][j] == '1')
				render(data, x_start, y_start, 0xFF0000);
			else
				render(data, x_start, y_start, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
