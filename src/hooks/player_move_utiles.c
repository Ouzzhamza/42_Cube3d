/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:58:04 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/20 12:15:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"

int	valid_move(t_raycast *raycast, int type)
{
	double x;
	double y;
	double x1;
	double y1;
	
	if (type == 1)
	{
		x = ((raycast->player->map_pos.x + raycast->player->speed * cos(raycast->player->angle)) / (CUB_SIZE / 2));
		y = ((raycast->player->map_pos.y + raycast->player->speed * sin(raycast->player->angle)) / (CUB_SIZE / 2));
	}
	else if (type == 2)
	{
		x = ((raycast->player->map_pos.x - raycast->player->speed * cos(raycast->player->angle)) / (CUB_SIZE / 2));
		y = ((raycast->player->map_pos.y - raycast->player->speed * sin(raycast->player->angle)) / (CUB_SIZE / 2));
	}
	else if (type == 3)
	{
		x = ((raycast->player->map_pos.x + raycast->player->speed * sin(raycast->player->angle)) / (CUB_SIZE / 2));
		y = ((raycast->player->map_pos.y  - raycast->player->speed * cos(raycast->player->angle)) / (CUB_SIZE / 2));
	}
	else 
	{
		x = ((raycast->player->map_pos.x - raycast->player->speed * sin(raycast->player->angle)) / (CUB_SIZE / 2));
		y = ((raycast->player->map_pos.y - raycast->player->speed * cos(raycast->player->angle)) / (CUB_SIZE / 2));
	}
	x1 = x + 0.125;
	y1 = y + 0.125;
	if (raycast->map->map[(int)y][(int)x] == '1' || raycast->map->map[(int)y1][(int)x] == '1' || \
	raycast->map->map[(int)y][(int)x1] == '1' || raycast->map->map[(int)y1][(int)x1] == '1')
		return(0);
	return(1);
}

void redraw(t_raycast *raycast)
{
	mlx_destroy_image(raycast->data->mlx_ptr, raycast->data->img.mlx_img);
	raycast->data->img.mlx_img = mlx_new_image(raycast->data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	render_image_color(raycast, raycast->map->ceiling, 0);
	render_image_color(raycast, raycast->map->floor, WIN_HEIGHT / 2);
	ray_casting(raycast);
	draw_minimap(raycast->data, raycast->map->map);
	trace_rays(raycast);
	render_player(raycast->data, raycast->player->map_pos.x, raycast->player->map_pos.y, 0x00FF00);
	mlx_put_image_to_window(raycast->data->mlx_ptr, raycast->data->win_ptr, raycast->data->img.mlx_img,0,0);
}