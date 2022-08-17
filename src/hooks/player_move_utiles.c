/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:58:04 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/17 11:45:42 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"

int	valid_move(t_raycast *raycast)
{
	double i;
	double j;

	i = raycast->player->map_pos.x + raycast->player->speed * cos(raycast->player->angle);
	j = raycast->player->map_pos.y + raycast->player->speed * sin(raycast->player->angle);
	i = i / CUB_SIZE;
	j = j / CUB_SIZE;

	if (raycast->map->map[(int)i][(int)j] ==  '1')
		return(0);
	return (1);
}

void redraw(t_raycast *raycast)
{
	mlx_destroy_image(raycast->data->mlx_ptr, raycast->data->img.mlx_img);
	raycast->data->img.mlx_img = mlx_new_image(raycast->data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	// draw_minimap(raycast->data, raycast->map->map);
	// render_player(raycast->data, raycast->player->map_pos.x, raycast->player->map_pos.y, 0x00FF00);
	ray_casting(raycast);
	mlx_put_image_to_window(raycast->data->mlx_ptr, raycast->data->win_ptr, raycast->data->img.mlx_img,0,0);
}
