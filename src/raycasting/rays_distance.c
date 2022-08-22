/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:43:43 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/22 21:13:06 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

double	calculate_ray_distance(t_point player_pos, t_point wall_pos)
{
	return (sqrt(pow(player_pos.x - wall_pos.x, 2) + pow(player_pos.y - wall_pos.y, 2)));
}


int	draw_wall(t_raycast *raycast, int x_start, double wall_height)
{
	double y_start;
	double wall_height_half;

	wall_height_half = wall_height / 2;
	y_start = raycast->centre_height;
	if (wall_height >= WIN_HEIGHT)
		drawline(raycast, x_start, 0, x_start, WIN_HEIGHT);
	else
	{
		drawline(raycast, x_start, y_start, x_start, raycast->centre_height - wall_height_half);
		drawline(raycast, x_start, y_start, x_start, raycast->centre_height + wall_height_half);
	}
	return (1);
}
void	trace_whole_line(t_raycast *raycast, int x_start, double wall_height, t_point intersc)
{
	int		i;
	int		x_offset;
	int		y_offset;
	int		draw_start;
	int		draw_end;

	draw_start = 0;
	draw_end = WIN_HEIGHT - 1;
	if (raycast->inters_type == 0)
		x_offset = (int)intersc.x % CUB_SIZE;
	else
		x_offset = (int)intersc.y % CUB_SIZE;
	i = draw_start;
	while (i <= draw_end)
	{
		y_offset = (i - draw_start) * ((float)(raycast->textures->height) / wall_height);
		raycast->data->img.addr [i * WIN_WIDTH + x_start] = raycast->textures->addr[(y_offset * raycast->textures->width) + x_offset];
		// my_mlx_put_pixel(raycast, x_start, i, );
		i++;
	}		
}

void	trace_start_end_line(t_raycast *raycast, int x_start, double wall_height, t_point interesc)
{
	int		i;
	int	x_offset;
	int	y_offset;
	int		draw_start;
	int		draw_end;

	draw_start = raycast->centre_height - (int)(wall_height / 2);
	draw_end = raycast->centre_height + (int)(wall_height / 2);
	if (raycast->inters_type == 0)
		x_offset = (int)interesc.x % CUB_SIZE;
	else
		x_offset = (int)interesc.y % CUB_SIZE;
	i = draw_start;
	while (i <= draw_end)
	{
		y_offset = (i - draw_start) * ((float)(raycast->textures->height) / wall_height);
		raycast->data->img.addr [i * WIN_WIDTH + x_start] = raycast->textures->addr[(y_offset * raycast->textures->width) + x_offset];
		// my_mlx_put_pixel(raycast, x_start, i, raycast->textures->addr[(y_offset * raycast->textures->width) + x_offset]);
		i++;
	}	
}

int	draw_horiz_texture(t_raycast *raycast, int x_start, double wall_height, t_point intersc)
{
	
	if (wall_height >= WIN_HEIGHT)
		trace_whole_line(raycast, x_start, wall_height, intersc);		
	else
		trace_start_end_line(raycast, x_start, wall_height, intersc);
	return (1);
}

int	draw_vertic_texture(t_raycast *raycast, int x_start, double wall_height, t_point intersc)
{
	if (wall_height >= WIN_HEIGHT)
		trace_whole_line(raycast, x_start, wall_height, intersc);
	else
		trace_start_end_line(raycast, x_start, wall_height, intersc);
	return(1);
}
// int	draw_horiz_texture(t_raycast *raycast, int x_start, double wall_height, t_point intersc)
// {
// 	int			y_start;
// 	double		pos;
// 	double		wall_height_half;
// 	double		res;
// 	int			i;
// 	int			j;
// 	int			coff;

// 	wall_height_half = wall_height / 2;
// 	pos = res - (int)(intersc.x / CUB_SIZE);
// 	j = (int)(pos * raycast->textures->width);
// 	coff = (int)(raycast->textures->height / wall_height_half);
// 	if (wall_height >= WIN_HEIGHT)
// 	{
// 		y_start = 0;
// 		i = 0;
// 		while (y_start < WIN_HEIGHT - 1)
// 		{
// 			my_mlx_put_pixel(raycast, x_start, y_start, raycast->textures->addr[i * raycast->textures->width + j]);
// 			y_start++;
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		y_start = (int)raycast->centre_height - wall_height_half;
// 		i = 0;
// 		while (y_start < raycast->centre_height)
// 		{
// 			my_mlx_put_pixel(raycast, x_start, y_start, raycast->textures->addr[i * raycast->textures->width + j]);
// 			y_start++;
// 			i++;
// 		}
// 		while (y_start < raycast->centre_height + wall_height_half)
// 		{
// 			my_mlx_put_pixel(raycast, x_start, y_start, raycast->textures->addr[i * raycast->textures->width + j]);
// 			y_start++;
// 			i++;
// 		}
// 	}
// 	return (1);
// }

// int	draw_vertic_texture(t_raycast *raycast, int x_start, double wall_height, t_point intersc)
// {
// 	int			y_start;
// 	double		pos;
// 	double		wall_height_half;
// 	double		res;
// 	int			i;
// 	int			j;
// 	int			coff;

// 	wall_height_half = wall_height / 2;
// 	res = intersc.y / CUB_SIZE;
// 	pos = res - (int)res;
// 	j = (int)(pos * raycast->textures->width);
// 	coff = (int)(raycast->textures->height / wall_height_half);
// 	if (wall_height >= WIN_HEIGHT)
// 	{
// 		y_start = 0;
// 		i = 0;
// 		while (y_start < WIN_HEIGHT - 1)
// 		{
// 			my_mlx_put_pixel(raycast, x_start, y_start, raycast->textures->addr[i * raycast->textures->width + j]);
// 			y_start++;
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		y_start = (int)raycast->centre_height - wall_height_half;
// 		i = 0;
// 		while (y_start < raycast->centre_height)
// 		{
// 			my_mlx_put_pixel(raycast, x_start, y_start, raycast->textures->addr[i * raycast->textures->width + j]);
// 			y_start++;
// 			i++;
// 		}
// 		while (y_start < raycast->centre_height + wall_height_half)
// 		{
// 			my_mlx_put_pixel(raycast, x_start, y_start, raycast->textures->addr[i * raycast->textures->width + j]);
// 			y_start++;
// 			i++;
// 		}
// 	}
// 	return (1);
// }
// int	draw_vertic_texture(t_raycast *raycast, int x_start, double wall_height, t_point intersc)
// {
// 	double	y_start;
// 	double	wall_height_half;
// 	double	offset;
// 	int		i;
// 	int		j;
// 	int		*addr;

// 	addr = NULL;
// 	wall_height_half = wall_height / 2;
// 	offset = intersc.y / CUB_SIZE;
// 	offset = offset - (int)offset;
// 	offset = offset * (double)raycast->textures->width;
// 	j = (int)(offset);
// 	i = 0;
// 	if (wall_height >= WIN_HEIGHT)
// 	{
// 		y_start = 0;
// 		while (y_start < WIN_HEIGHT - 1)
// 		{
// 			addr = (int *)&raycast->textures->addr[i * (int)(raycast->textures->width) + j];
// 			my_mlx_put_pixel(raycast, x_start, y_start, *addr);
// 			i++;
// 			y_start++;
// 		}
// 	}
// 	else
// 	{
// 		y_start = raycast->centre_height;
// 		while (y_start < raycast->centre_height + wall_height_half)
// 		{
// 			addr = (int *)&raycast->textures->addr[i * (int)(raycast->textures->width) + j];
// 			i++;
// 			y_start++;
// 		}
// 		y_start = raycast->centre_height - wall_height_half;
// 		while(y_start <= raycast->centre_height)
// 		{
// 			addr = (int *)&raycast->textures->addr[i * (int)(raycast->textures->width) + j];
// 			i++;
// 			y_start++;
// 		}
// 	}
// 	return (1);
// }