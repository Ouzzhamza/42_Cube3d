/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:53:13 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/21 16:05:25 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"


void move_forward(t_raycast *raycast)
{
	// if (valid_move(raycast, 1))
	// {
		raycast->player->map_pos.x += raycast->player->speed * cos(raycast->player->angle);
		raycast->player->map_pos.y += raycast->player->speed * sin(raycast->player->angle);
	// }
}

void retreat(t_raycast *raycast)
{
	// if (valid_move(raycast, 2))
	// {
		raycast->player->map_pos.x -= raycast->player->speed * cos(raycast->player->angle);
		raycast->player->map_pos.y -= raycast->player->speed * sin(raycast->player->angle);
	// }
}

void move_right(t_raycast *raycast)
{
	// if (valid_move(raycast, 3))
	// {
		raycast->player->map_pos.x += raycast->player->speed * sin(raycast->player->angle);
		raycast->player->map_pos.y -= raycast->player->speed * cos(raycast->player->angle);	
	// }
}

void move_left(t_raycast *raycast)
{
	//  if (valid_move(raycast, 4))
	//  {
		raycast->player->map_pos.x -= raycast->player->speed * sin (raycast->player->angle);
		raycast->player->map_pos.y -= raycast->player->speed * cos(raycast->player->angle);
	//  }
}

