/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:59:00 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/30 23:00:05 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

int	mouse_move(int x, int y, t_raycast *raycast)
{
	int	diff;

	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_WIDTH)
	{
		diff = x - raycast->x;
		if (diff > 0)
			raycast->player->angle += 0.0374533;
		else if (diff < 0)
			raycast->player->angle -= 0.0374533;
		raycast->x = x;
	}
	return (0);
}