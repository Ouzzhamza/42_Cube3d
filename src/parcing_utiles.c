/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:21:30 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/29 19:07:39 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"


int identifire(char **str, t_map *map)
{

    printf("%d\n", open("./assets/brick.xpm", O_RDONLY));
    
    if (!ft_strcmp(str[0], NORTH) || !ft_strcmp(str[0], EAST) || \
        !ft_strcmp(str[0], WEST) || !ft_strcmp(str[0], SOUTH))
        {
            if(open("./assets/brick.xpm", O_RDONLY) == -1)
            {
                printf("%s\n", str[1]);
                ft_error(MAP);
            }
            else
                map->identifier++; 
        }
        printf("%d\n", map->identifier);
        return(0);
}
