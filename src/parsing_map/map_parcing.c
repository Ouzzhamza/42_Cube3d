/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:12:07 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/20 11:14:07 by houazzan         ###   ########.fr       */
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
}