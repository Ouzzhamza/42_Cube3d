/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:23:54 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/19 18:36:31 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

t_img   *load_xpm_files(t_raycast *raycast)
{
    t_img   *textures;
    int     height;
    int     width;

    height = 0;
    width = 0;
    textures = (t_img *)malloc(sizeof(t_img) * 4);
    if (!textures)
        ft_error("Malloc Error\n");
    textures[NO].mlx_img = mlx_xpm_file_to_image(raycast->data->mlx_ptr, raycast->map->wall[NO], textures[NO].width, textures[NO].height);
    textures[SO].mlx_img = mlx_xpm_file_to_image(raycast->data->mlx_ptr, raycast->map->wall[SO], textures[SO].width, textures[SO].height);
    textures[WE].mlx_img = mlx_xpm_file_to_image(raycast->data->mlx_ptr, raycast->map->wall[WE], textures[WE].width, textures[WE].height);
    textures[EA].mlx_img = mlx_xpm_file_to_image(raycast->data->mlx_ptr, raycast->map->wall[EA], textures[EA].width, textures[EA].height);
    return (textures);
}