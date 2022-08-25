/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:23:54 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/23 12:27:34 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

void    load_xpm_files(t_raycast *raycast)
{
    int     height;
    int     width;

    height = 0;
    width = 0;
    raycast->textures = (t_img *)malloc(sizeof(t_img));
    if (!raycast->textures)
        ft_error("Malloc Error\n");
    raycast->textures->mlx_img = mlx_xpm_file_to_image(raycast->data->mlx_ptr, raycast->map->wall[NO], &raycast->textures->width, &raycast->textures->height);
    raycast->textures->addr = (int *)mlx_get_data_addr(raycast->textures->mlx_img, &raycast->textures->bpp, &raycast->textures->line_len, &raycast->textures->endian);
}