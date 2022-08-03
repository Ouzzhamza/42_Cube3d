/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:00 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/03 15:13:33 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
} t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;
}t_rect;


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

void	draw_minimap(t_data *data, char **map, int width, int height)
{
	int i;
	int	j;
	int x_start;
	int y_start;

	i = 0;
	y_start = 0;
	while (map[i])
	{
		j = 0;
		x_start = 0;
		while (map[i][j])
		{
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
				render(data, x_start, y_start, 0x00FF00);
			x_start += 64;
			j++;
		}
		y_start += 64;
		i++;
	}
}

// int	main(void)
// {
// 	t_data	data;
// 	char	*tab[6] = {  "  111111   111111111"
// 						," 100000E111111     1"
// 						,"11111011     1111111"
// 						,"1001 111111111000001"
// 						,"111111 11 111 1     ", NULL};

// 	data.mlx_ptr= mlx_init();
// 	if (data.mlx_ptr == NULL)
// 		return (1);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "My Window");
// 	if (data.win_ptr == NULL)
// 	{
// 		free (data.win_ptr);
// 		return (1);
// 	}
// 	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
// 	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
// 	draw_minimap(&data, tab, WIN_WIDTH, WIN_HEIGHT);
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
// 	mlx_loop(data.mlx_ptr);
// 	free (data.mlx_ptr);
// }