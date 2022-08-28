/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:51:26 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/28 14:54:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

void	ft_error(char *str, t_map *map)
{
	free_map(map);
	ft_putstr("Error\n");
	ft_putstr(str);
	exit (EXIT_FAILURE);
}
