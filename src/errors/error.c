/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:51:26 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/31 22:42:50 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

void	ft_error(char *str, t_map *map)
{
	ft_putstr("Error\n");
	if (!ft_strcmp("No map or player does not exist on map", str))
		printf("%s\n", str);
	else
		printf("at line : %s\n", str);
	if (map)
		free_map(map);
	exit (EXIT_FAILURE);
}
