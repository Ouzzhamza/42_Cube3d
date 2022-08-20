/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:25:12 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/19 11:45:42 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"


int ft_exit(t_raycast *raycast)
{
	mlx_destroy_image(raycast->data->mlx_ptr, raycast->data->img.addr);
	mlx_destroy_window(raycast->data->mlx_ptr, raycast->data->win_ptr);
	exit(0);
	
}

int  key_type(int key, t_raycast *raycast)
{
	if (key == 53)
		ft_exit(raycast);
	else if (key == 13 || key == 126)
		move_forward(raycast);
	else if (key == 1 || key == 125)
		retreat(raycast);
	else if (key == 2)
		move_left(raycast);
	else if (key == 0)
		move_right(raycast);
	else if (key == 123)
		raycast->player->angle -= 0.174533;
	else if (key == 124)
		raycast->player->angle += 0.174533;
	redraw(raycast);
	return(0);
}

void hooks(t_raycast *raycast)
{
    mlx_hook(raycast->data->win_ptr, 17, 0, ft_exit, raycast);
	mlx_hook(raycast->data->win_ptr, 2, 0, key_type, raycast);
}