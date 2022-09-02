/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:51:26 by houazzan          #+#    #+#             */
/*   Updated: 2022/09/02 15:56:32 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

void	ft_error(char *str, t_map *map, int type)
{
	ft_putstr("Error\n");
	if (type == 1)
		printf("at line : %s\n", str);
	else
		printf("%s\n", str);
	if (map)
		free_map(map);
	exit (EXIT_FAILURE);
}
