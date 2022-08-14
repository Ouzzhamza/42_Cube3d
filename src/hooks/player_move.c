/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:53:13 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/14 21:07:21 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"


void move_forward(t_raycast *raycast)
{
	// if (valid_move(raycast))
	// {
		raycast->player->map_pos.x += raycast->player->speed * cos(raycast->player->angle);
		raycast->player->map_pos.y += raycast->player->speed * sin(raycast->player->angle);
	// }
}


void retreat(t_raycast *raycast)
{
	// if (valid_move(raycast))
	// {
		raycast->player->map_pos.x -= raycast->player->speed * cos(raycast->player->angle);
		raycast->player->map_pos.y -= raycast->player->speed * sin(raycast->player->angle);
	// }
}


void move_right(t_raycast *raycast)
{
	raycast->player->map_pos.x += raycast->player->speed / 2;
}

void move_left(t_raycast *raycast)
{
	// if (valid_move(raycast))
	// {
		raycast->player->map_pos.x -= raycast->player->speed / 2;
	// }
}

