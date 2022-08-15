/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:48:36 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/15 12:59:10 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/cube3d.h"

double	player_angle(char direction)
{
	if (direction == 'E')
		return (0);
	if (direction == 'N')
		return (M_PI / 2);
	if (direction == 'W')
		return (M_PI);
	if (direction == 'S')
		return ((3 * M_PI) / 2);
	return (1);
}

t_point	get_player_pos(char **map)
{
	int		i;
	int		j;
	t_point	player;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'N')
			{
				player.x = (j * CUB_SIZE);
				player.y = (i * CUB_SIZE);
			}
			j++;
		}
		i++;
	}
	return (player);
}

t_player	*player_data_init(t_map *map)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		ft_error("Malloc Error");
	player->map_pos = get_player_pos(map->map);
	player->angle = player_angle(map->player);
	player->speed = 10;
	return (player);
}

t_raycast	*raycast_data_init(t_data *data, t_map *map, t_player *player)
{
	t_raycast	*raycast;

	raycast = (t_raycast *)malloc(sizeof(t_raycast));
	if (!raycast)
		ft_error("Malloc Error");
	raycast->rays = (double *)malloc(sizeof(double) * WIN_WIDTH);
	if (!raycast->rays)
		ft_error("Malloc Error");
	raycast->data = data;
	raycast->map = map;
	raycast->player = player;
	raycast->angle = M_PI / 3;
	raycast->dis_plane = WIN_WIDTH / tan(M_PI / 6);
	raycast->increment_angle = (M_PI / 3) / WIN_WIDTH;
	return (raycast);
}