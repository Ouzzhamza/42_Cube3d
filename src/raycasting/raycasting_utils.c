/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:54:41 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/27 20:17:34 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

double	player_angle(char direction)
{
	if (direction == 'E')
		return (0);
	if (direction == 'N')
		return ((3 * M_PI) / 2);
	if (direction == 'W')
		return (M_PI);
	if (direction == 'S')
		return ((M_PI / 2));
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
				player.x = j;
				player.y = i;
			}
			j++;
		}
		i++;
	}
	return (player);
}

t_point	minimap_player_pos(char **map)
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
				player.x = j * CUB_SIZE;
				player.y = i * CUB_SIZE;
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
	ft_memset(player, 0, sizeof(t_player));
	player->minimap_pos = minimap_player_pos(map->map);
	player->angle = player_angle(map->player);
	player->speed = 1;
	return (player);
}

t_raycast	*raycast_data_init(t_data *data, t_map *map, t_player *player)
{
	t_raycast	*raycast;

	raycast = (t_raycast *)malloc(sizeof(t_raycast));
	if (!raycast)
		ft_error("Malloc Error");
	raycast->x = (double *)malloc((WIN_WIDTH) * sizeof(double));
	raycast->y = (double *)malloc((WIN_WIDTH) * sizeof(double));
	raycast->data = data;
	raycast->map = map;
	raycast->player = player;
	raycast->half_width = WIN_WIDTH / 2;
	raycast->centre_height = WIN_HEIGHT / 2;
	raycast->angle = M_PI / 3;
	raycast->dis_plane = raycast->half_width / tan(M_PI / 6);
	raycast->increment_angle = (M_PI / (3 * WIN_WIDTH));
	return (raycast);
}
