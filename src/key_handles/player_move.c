/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:53:13 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/14 10:11:26 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"

int	check_valid_move(t_map *map, int x, int y)
{
	int i;
	int	j;

	i = y / CUB_SIZE;
	j = x / CUB_SIZE;
	if (y % CUB_SIZE || x % CUB_SIZE)
	{
		if (x % CUB_SIZE && map->map[i][j + 1] == '1')
			return (0);
		if (y % CUB_SIZE && map->map[i + 1][j] == '1')
			return (0);
	}
	else
	{
		if (map->map[i + 1][j + 1] == '1')
			return (0);
	}
	return (1);
}

int	handle_player_move(int key, void *data)
{
	t_raycast	raycast;
	// t_point		ray;

	raycast = *(t_raycast *)data;
	if (key == 13)
	{
		raycast.player->map_pos.x += raycast.player->speed * cos(raycast.player->angle);
		raycast.player->map_pos.y += raycast.player->speed * sin(raycast.player->angle);
		mlx_destroy_image(raycast.data->mlx_ptr, raycast.data->img.mlx_img);
		raycast.data->img.mlx_img = mlx_new_image(raycast.data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		draw_minimap(raycast.data, raycast.map->map);
		render_player(raycast.data, raycast.player->map_pos.x, raycast.player->map_pos.y, 0x00FF00);
		trace_rays(&raycast);
		mlx_put_image_to_window(raycast.data->mlx_ptr, raycast.data->win_ptr, raycast.data->img.mlx_img,0,0);	
	}
	if (key == 1)
	{
		raycast.player->map_pos.x -= raycast.player->speed * cos(raycast.player->angle);
		raycast.player->map_pos.y -= raycast.player->speed * sin(raycast.player->angle);
		mlx_destroy_image(raycast.data->mlx_ptr, raycast.data->img.mlx_img);
		raycast.data->img.mlx_img = mlx_new_image(raycast.data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		draw_minimap(raycast.data, raycast.map->map);
		render_player(raycast.data, raycast.player->map_pos.x, raycast.player->map_pos.y, 0x00FF00);
		trace_rays(&raycast);
		mlx_put_image_to_window(raycast.data->mlx_ptr, raycast.data->win_ptr, raycast.data->img.mlx_img,0,0);	
	}
	if (key == 0)
	{
		raycast.player->angle -= 0.174533;
		mlx_destroy_image(raycast.data->mlx_ptr, raycast.data->img.mlx_img);
		raycast.data->img.mlx_img = mlx_new_image(raycast.data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		draw_minimap(raycast.data, raycast.map->map);
		render_player(raycast.data, raycast.player->map_pos.x, raycast.player->map_pos.y, 0x00FF00);
		trace_rays(&raycast);
		mlx_put_image_to_window(raycast.data->mlx_ptr, raycast.data->win_ptr, raycast.data->img.mlx_img,0,0);
	}
	if (key == 2)
	{
		raycast.player->angle += 0.174533;
		mlx_destroy_image(raycast.data->mlx_ptr, raycast.data->img.mlx_img);
		raycast.data->img.mlx_img = mlx_new_image(raycast.data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		draw_minimap(raycast.data, raycast.map->map);
		render_player(raycast.data, raycast.player->map_pos.x, raycast.player->map_pos.y, 0x00FF00);
		trace_rays(&raycast);
		mlx_put_image_to_window(raycast.data->mlx_ptr, raycast.data->win_ptr, raycast.data->img.mlx_img,0,0);
	}
	return (0);
}

int	close_win(int key, void *param)
{
	t_raycast raycast;

	raycast = *(t_raycast *)param;
	if (key == 53)
	{
		// mlx_clear_window(raycast.data->mlx_ptr, raycast.data->win_ptr);
		// mlx_destroy_image(raycast.data->mlx_ptr ,raycast.data->img.mlx_img);
		// mlx_destroy_window(raycast.data->mlx_ptr, raycast.data->win_ptr);
		// free_map(raycast.map);
		exit (EXIT_SUCCESS);
	}
	return (1);
}

int	red_cross(void *param)
{
	t_raycast raycast;

	raycast = *(t_raycast *)param;
	// mlx_clear_window(raycast.data->mlx_ptr, raycast.data->win_ptr);
	// mlx_destroy_image(raycast.data->mlx_ptr ,raycast.data->img.mlx_img);
	// mlx_destroy_window(raycast.data->mlx_ptr, raycast.data->win_ptr);
	// free_map(raycast.map);
	exit (EXIT_SUCCESS);
	return (1);
}
