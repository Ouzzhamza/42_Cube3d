/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:42:39 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/14 14:32:50 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

double	get_horizontal_intersection(t_raycast *raycast, double angle)
{
	double	x_intersection;
	double	y_intersection;
	double	dx;
	double	dy;
	t_point	grid;

	y_intersection = round(raycast->player->map_pos.y / CUB_SIZE) * CUB_SIZE;
	x_intersection = raycast->player->map_pos.x + (raycast->player->map_pos.y - y_intersection) / tan(angle);
	dy = CUB_SIZE;
	dx = dy / tan(angle);
	grid.x = x_intersection / CUB_SIZE;
	grid.y = y_intersection / CUB_SIZE;
	while (raycast->map->map[(int)grid.y][(int)grid.x] != '1')
	{
		y_intersection += dy;
		x_intersection += dx;
		grid.x = x_intersection / CUB_SIZE;
		grid.y = y_intersection / CUB_SIZE;
	}
	return (fabs(raycast->player->map_pos.x - x_intersection) / cos (angle));
}

double	get_vertical_intersection(t_raycast *raycast, double angle)
{
	double	x_intersection;
	double	y_intersection;
	double	dx;
	double	dy;
	t_point	grid;

	x_intersection = round(raycast->player->map_pos.x / CUB_SIZE) * CUB_SIZE;
	y_intersection = raycast->player->map_pos.y + (raycast->player->map_pos.x - x_intersection) / tan(angle);
	dx = CUB_SIZE;
	dy = dx * tan(angle);
	grid.x = x_intersection / CUB_SIZE;
	grid.y = y_intersection / CUB_SIZE;
	while (raycast->map->map[(int)grid.y][(int)grid.x] != '1')
	{
		y_intersection += dy;
		x_intersection += dx;
		grid.x = x_intersection / CUB_SIZE;
		grid.y = y_intersection / CUB_SIZE;
		printf("%f --- %f\n", grid.x, grid.y);
	}
	return(fabs(raycast->player->map_pos.x - x_intersection) / cos(angle));
}

double get_intersection(t_raycast *raycast, double angle)
{
	double	vertical_inter;
	double	horizontal_inter;

	horizontal_inter = get_horizontal_intersection(raycast, angle);
	vertical_inter = get_vertical_intersection(raycast, angle);
	// printf("Here\n");
	if (vertical_inter > horizontal_inter)
		return (vertical_inter);
	return (horizontal_inter);
}

t_point	get_horiz_inters_point(t_raycast *raycast, double angle)
{
	double	x_intersection;
	double	y_intersection;
	double	dx;
	double	dy;
	t_point	grid;

	if (angle >= 0 &&  angle <= M_PI)
	{
		y_intersection = ((int)(raycast->player->map_pos.y) / CUB_SIZE ) * CUB_SIZE - 1;
		dy = -CUB_SIZE;
	}
	else
	{
		y_intersection = ((int)(raycast->player->map_pos.y) / CUB_SIZE ) * CUB_SIZE;
		dy = CUB_SIZE;	
	}
	x_intersection = raycast->player->map_pos.x + (raycast->player->map_pos.y - y_intersection) / tan(angle);
	dx = CUB_SIZE / tan(angle);
	grid.x = x_intersection / CUB_SIZE;
	grid.y = y_intersection / CUB_SIZE;
	while (raycast->map->map[(int)grid.y][(int)grid.x] != '1')
	{
		x_intersection += dx;
		y_intersection += dy;
		grid.x = x_intersection / CUB_SIZE;
		grid.y = y_intersection / CUB_SIZE;
	}
	grid.x = x_intersection;
	grid.y = y_intersection;
	return (grid);
}

t_point	get_verti_inters_point(t_raycast *raycast, double angle)
{
	double	x_intersection;
	double	y_intersection;
	double	dx;
	double	dy;
	t_point	grid;

	if ((angle >= 0 && angle <= (M_PI / 2)) || (angle < 0 && angle >= ((2 * M_PI) / 3)))
	{
		x_intersection = ((int)(raycast->player->map_pos.x) / CUB_SIZE )* CUB_SIZE + CUB_SIZE;
		dx = CUB_SIZE;
	}
	else
	{
		x_intersection = ((int)(raycast->player->map_pos.x) / CUB_SIZE )* CUB_SIZE - 1;
		dx = -CUB_SIZE;
	}
	y_intersection = raycast->player->map_pos.y + (raycast->player->map_pos.x - x_intersection) / tan(angle);
	dy = CUB_SIZE * tan(angle);
	grid.x = x_intersection / CUB_SIZE;
	grid.y = y_intersection / CUB_SIZE;
	while (raycast->map->map[(int)grid.y][(int)grid.x] != '1')
	{
	printf("%f ---- %f\n", grid.x, grid.y);
		x_intersection += dx;
		y_intersection += dy;
		grid.x = x_intersection / CUB_SIZE;
		grid.y = y_intersection / CUB_SIZE;
	}
	grid.x = x_intersection;
	grid.y = y_intersection;
	// printf("Here\n");
	return (grid);
}


int	ray_casting(t_raycast *raycast)
{
	int	i;
	double	ray_angle;
	t_point	ray;

	i = 0;
	ray_angle = raycast->player->angle - (M_PI / 6);
	while (i < WIN_WIDTH)
	{
		printf("%d here\n", i);
		ray = get_horiz_inters_point(raycast, ray_angle);
		// ray = get_verti_inters_point(raycast, ray_angle);
		// printf("%f --- %f \n", ray.x, ray.y);
		// printf("%f -- %f\n",ray.x, ray.y);
		drawline(raycast->data, raycast->player->map_pos.x ,raycast->player->map_pos.y, ray.x,ray.y);
		// printf("Good\n");
		ray_angle += raycast->increment_angle;
		i++;
	}
	return (1);
}
