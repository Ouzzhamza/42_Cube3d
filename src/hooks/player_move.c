/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:53:13 by mmoumni           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/22 23:11:40 by houazzan         ###   ########.fr       */
=======
/*   Updated: 2022/08/21 16:05:25 by mmoumni          ###   ########.fr       */
>>>>>>> ddb35a5b71d33c1086019ae761a42c65c76b8924
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"


int move_forward(t_raycast *raycast)
{
<<<<<<< HEAD
	if ( valid_move(raycast, 1))
	{
		raycast->player->map_pos.x += raycast->player->speed * cos(raycast->player->angle);
		raycast->player->map_pos.y += raycast->player->speed * sin(raycast->player->angle);
	}
	return 0;
	
=======
	// if (valid_move(raycast, 1))
	// {
		raycast->player->map_pos.x += raycast->player->speed * cos(raycast->player->angle);
		raycast->player->map_pos.y += raycast->player->speed * sin(raycast->player->angle);
	// }
>>>>>>> ddb35a5b71d33c1086019ae761a42c65c76b8924
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

