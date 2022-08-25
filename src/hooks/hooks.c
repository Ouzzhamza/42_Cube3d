/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:25:12 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/23 20:48:28 by houazzan         ###   ########.fr       */
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


int  key_type_pres(int key, t_raycast *raycast)
{
	if (key == 53)
		raycast->player->exit = 1;
	else if (key == 13 || key == 126)
		raycast->player->advance = 1;
    else if (key == 1 || key == 125)
		raycast->player->retreat = 1;
	else if (key == 2)
		raycast->player->right = 1;
	else if (key == 0)
		raycast->player->left = 1;
	else if (key == 123)
		raycast->player->l_rotate = 1;
	else if (key == 124)
		raycast->player->r_rotate = 1;
	return(0);
}

int	key_type_releas(int key, t_raycast *raycast)
{
	if (key == 13 || key == 126)
		raycast->player->advance = 0;
   else if (key == 1 || key == 125)
		raycast->player->retreat = 0;
	else if (key == 2)
		raycast->player->right = 0;
	else if (key == 0)
		raycast->player->left = 0;
	else if (key == 123)
		raycast->player->l_rotate = 0;
	else if (key == 124)
		raycast->player->r_rotate = 0;
	return(0);

}

int handle_event(t_raycast *raycast)
{
	if (raycast->player->exit == 1)
		ft_exit(raycast);
	if (raycast->player->advance == 1)
		move_forward(raycast);
	if (raycast->player->retreat == 1)
		retreat(raycast);
	if (raycast->player->right == 1)
		move_right(raycast);
	if (raycast->player->left == 1)
		move_left(raycast);
	if (raycast->player->l_rotate == 1)
		raycast->player->angle -= 0.0374533;
	if (raycast->player->r_rotate == 1)
		raycast->player->angle += 0.0374533;
	redraw(raycast);
	return(0);
		
	
}

void hooks(t_raycast *raycast)
{
    mlx_hook(raycast->data->win_ptr, 17, 0, ft_exit, raycast);
	mlx_hook(raycast->data->win_ptr, 3, 0, key_type_releas, raycast);
	mlx_hook(raycast->data->win_ptr, 2, 0, key_type_pres, raycast);
	mlx_loop_hook(raycast->data->mlx_ptr, handle_event, raycast);
}