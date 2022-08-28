/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:53:13 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/28 15:13:30 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

void	move_forward(t_raycast *raycast)
{
	if (valid_move(raycast, 1))
	{
		raycast->player->minimap_pos.x += raycast->player->speed * \
			cos(raycast->player->angle);
		raycast->player->minimap_pos.y += raycast->player->speed * \
			sin(raycast->player->angle);
	}	
}

void	retreat(t_raycast *raycast)
{
	if (valid_move(raycast, 2))
	{
		raycast->player->minimap_pos.x -= raycast->player->speed * \
		cos(raycast->player->angle);
		raycast->player->minimap_pos.y -= raycast->player->speed * \
		sin(raycast->player->angle);
	}
}

void	move_right(t_raycast *raycast)
{
	if (valid_move(raycast, 3))
	{
		raycast->player->minimap_pos.x -= raycast->player->speed * \
		sin(raycast->player->angle);
		raycast->player->minimap_pos.y += raycast->player->speed * \
		cos(raycast->player->angle);
	}
}

void	move_left(t_raycast *raycast)
{
	if (valid_move(raycast, 4))
	{
		raycast->player->minimap_pos.x += raycast->player->speed * \
		sin (raycast->player->angle);
		raycast->player->minimap_pos.y -= raycast->player->speed * \
		cos(raycast->player->angle);
	}
}
