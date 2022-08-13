/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:53:13 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/13 13:39:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"

int	valid_move(t_map *map, int x, int y)
{
	int i;
	int	j;
	(void)(map);

	i = x * CUB_SIZE;
	j = y * CUB_SIZE;
	//	printf("i = %d\n", j);
	 //if (map->map[i][j + 2] == '1' || map->map[i][j - 2] == '1')
		// printf("j = %d\n", j);
		printf("j = %c\n", map->map[7][10]);
	// if (y % CUB_SIZE || x % CUB_SIZE)
	// {
	// 	if (x % CUB_SIZE && map->map[i][j + 1] == '1')
	// 		return (0);
	// 	if (y % CUB_SIZE && map->map[i + 1][j] == '1')
	// 		return (0);
	// }
	// else
	// {
	// 	if (map->map[i + 1][j + 1] == '1')
	// 		return (0);
	// }
	return (1);
}


void move_forward(t_raycast *raycast)
{
	// printf("%f\n", raycast->player->map_pos.y);
	// int i = raycast->player->map_pos.y / CUB_SIZE;
	// printf("%d\n", i);
	// raycast->player->map_pos.x += raycast->player->speed * cos(raycast->player->angle);
	if (valid_move(raycast->map, raycast->player->map_pos.x, raycast->player->map_pos.y))
		raycast->player->map_pos.y += raycast->player->speed * sin(raycast->player->angle);
	//printf("%f\n", raycast->player->map_pos.y);
}


void retreat(t_raycast *raycast)
{
	//raycast->player->map_pos.x -= raycast->player->speed * cos(raycast->player->angle);
	raycast->player->map_pos.y -= raycast->player->speed * sin(raycast->player->angle);
}


void redraw(t_raycast *raycast)
{
	t_point ray;

	mlx_destroy_image(raycast->data->mlx_ptr, raycast->data->img.mlx_img);
	raycast->data->img.mlx_img = mlx_new_image(raycast->data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	draw_minimap(raycast->data, raycast->map->map);
	render_player(raycast->data, raycast->player->map_pos.x, raycast->player->map_pos.y, 0x00FF00);
	ray.x = raycast->player->map_pos.x + 30 * cos(raycast->player->angle);
	ray.y = raycast->player->map_pos.y + 30 * sin(raycast->player->angle);
	drawline(raycast->data, raycast->player->map_pos.x, raycast->player->map_pos.y, ray.x, ray.y);
	mlx_put_image_to_window(raycast->data->mlx_ptr, raycast->data->win_ptr, raycast->data->img.mlx_img,0,0);
}


