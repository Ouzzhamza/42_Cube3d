/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:48:36 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/14 18:34:01 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/cube3d.h"

double	convert_degree_to_radian(double degree)
{
	return ((degree * M_PI) / 180);
}

double	player_angle(char direction)
{
	if (direction == 'E')
		return (0);
	if (direction == 'S')
		return (M_PI / 2);
	if (direction == 'W')
		return (M_PI);
	if (direction == 'N')
		return (-(M_PI / 2));
	return (1);
}

int	player_data_init(t_map *map, t_player *player)
{
	player->angle = player_angle(map->player);
	player->speed = 10;
	return (1);
}

t_raycast	raycast_data_init(t_data *data, t_map *map, t_player *player)
{
	t_raycast	raycast_struc;

	raycast_struc.data = data;
	raycast_struc.map = map;
	raycast_struc.player = player;
	return (raycast_struc);
}