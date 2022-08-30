/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:52:07 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/30 16:56:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

void	free_table(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
}

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (map->wall[i])
	{
		free(map->wall[i]);
		i++;
	}
}
