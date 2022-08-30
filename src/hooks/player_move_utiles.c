/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:58:04 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/30 22:46:02 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs.h"

t_point	check_up_down_move(t_raycast *raycast, int type)
{
	double	x;
	double	y;

	if (type == 1)
	{
		x = (((raycast->player->minimap_pos.x + \
		raycast->player->speed * cos(raycast->player->angle)) / (CUB_SIZE)));
		y = ((((raycast->player->minimap_pos.y + raycast->player->speed * \
		sin(raycast->player->angle)) / (CUB_SIZE)))) - 0.01;
	}
	else
	{
		x = ((raycast->player->minimap_pos.x - \
		raycast->player->speed * cos(raycast->player->angle)) / (CUB_SIZE));
		y = ((raycast->player->minimap_pos.y - \
		raycast->player->speed * sin(raycast->player->angle)) / (CUB_SIZE));
	}
	return ((t_point){x, y});
}

t_point	check_left_right_move(t_raycast *raycast, int type)
{
	double	x;
	double	y;

	if (type == 3)
	{
		x = ((raycast->player->minimap_pos.x - \
		raycast->player->speed * sin(raycast->player->angle)) / (CUB_SIZE));
		y = ((raycast->player->minimap_pos.y + \
		raycast->player->speed * cos(raycast->player->angle)) / (CUB_SIZE));
	}
	else
	{
		x = ((raycast->player->minimap_pos.x + raycast->player->speed * \
		sin(raycast->player->angle)) / (CUB_SIZE)) - 0.01;
		y = ((raycast->player->minimap_pos.y - raycast->player->speed * \
		cos(raycast->player->angle)) / (CUB_SIZE));
	}
	return ((t_point){x, y});
}

int	valid_move(t_raycast *raycast, int type)
{
	t_point	p;
	double	x;
	double	y;

	if (type == 1 || type == 2)
		p = check_up_down_move(raycast, type);
	else
		p = check_left_right_move(raycast, type);
	x = p.x + 0.025;
	y = p.y + 0.025;
	if (raycast->map->map[(int)p.y][(int)p.x] == '1' \
	|| raycast->map->map[(int)y][(int)p.x] == '1' \
	|| raycast->map->map[(int)p.y][(int)x] == '1' \
	|| raycast->map->map[(int)y][(int)x] == '1' \
	|| raycast->map->map[(int)p.y][(int)p.x] == ' ' \
	|| raycast->map->map[(int)y][(int)p.x] == ' ' \
	|| raycast->map->map[(int)p.y][(int)x] == ' ' \
	|| raycast->map->map[(int)y][(int)x] == ' ')
		return (0);
	return (1);
}

int	redraw(t_raycast *raycast)
{
	mlx_clear_window(raycast->data->mlx_ptr, raycast->data->win_ptr);
	mlx_destroy_image(raycast->data->mlx_ptr, raycast->data->img.mlx_img);
	raycast->data->img.mlx_img = mlx_new_image(raycast->data->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT);
	render_image_color(raycast, raycast->map->ceiling, 0);
	render_image_color(raycast, raycast->map->floor, WIN_HEIGHT / 2);
	ray_casting(raycast);
	draw_minimap(raycast, raycast->map->map);
	mlx_put_image_to_window(raycast->data->mlx_ptr, \
	raycast->data->win_ptr, raycast->data->img.mlx_img, 0, 0);
	return (0);
}
