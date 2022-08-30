/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:23:54 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 17:06:52 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs.h"

t_img	*get_texture_by_direc(t_raycast *raycast, double angle)
{
	if (raycast->inters_type == 0)
	{
		if (angle > M_PI && angle < (2 * M_PI))
			return (&raycast->textures[NO]);
		else
			return (&raycast->textures[SO]);
	}
	else
	{
		if ((angle < M_PI / 2) || (angle > 1.5 * M_PI))
			return (&raycast->textures[EA]);
		else
			return (&raycast->textures[WE]);
	}
	return (NULL);
}

void	load_xpm_files(t_raycast *raycast)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		raycast->textures[i].mlx_img = mlx_xpm_file_to_image(\
		raycast->data->mlx_ptr, raycast->map->wall[i], \
		&raycast->textures[i].width, &raycast->textures[i].height);
		if (raycast->textures[i].mlx_img == NULL)
			ft_error("Mlx_Xpm_Error\n", raycast->map);
		raycast->textures[i].addr = (int *)mlx_get_data_addr(\
		raycast->textures[i].mlx_img, &raycast->textures[i].bpp, \
		&raycast->textures[i].line_len, &raycast->textures[i].endian);
		i++;
	}
}
