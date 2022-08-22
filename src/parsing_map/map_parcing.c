/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:12:07 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/21 21:16:12 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

void    get_dimension_of_map(t_map *map, int *width, int *height)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (map->map[0][j])
        j++;
    *width = j;
    while (map->map[i])
        i++;
    *height = i;
    map->x_scall = WIN_WIDTH / (WIN_WIDTH / 2);
    map->y_scall = WIN_HEIGHT / (WIN_HEIGHT / 2);
    printf("%d\n", map->x_scall);
    printf("%d\n", map->y_scall);
}