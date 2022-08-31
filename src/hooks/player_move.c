/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:53:13 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/31 11:21:39 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs.h"

void	move_forward(t_raycast *raycast)
{
		raycast->player->minimap_pos = valid_move(raycast, 1);
}

void	retreat(t_raycast *raycast)
{
	raycast->player->minimap_pos = valid_move(raycast, 2);
}

void	move_right(t_raycast *raycast)
{
	raycast->player->minimap_pos = valid_move(raycast, 3);
}

void	move_left(t_raycast *raycast)
{
	raycast->player->minimap_pos = valid_move(raycast, 4);
}
