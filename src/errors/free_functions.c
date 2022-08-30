/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 08:29:23 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 17:05:46 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/structs.h"

void	free_map(t_map *map)
{
	if (map->list)
		free_list(map->list);
	if (map->map)
		free_two_dim_arr((void *)map->map);
	free_two_dim_arr((void *)map->wall);
}

void	free_two_dim_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
}

void	free_list(t_list *list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	free_tab(void *tab)
{
	free (tab);
}

void	free_raycast(t_raycast *raycast)
{
	free_map(raycast->map);
	free(raycast->player);
	free(raycast);
}
