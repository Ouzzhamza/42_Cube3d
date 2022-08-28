/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 08:29:23 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/28 14:53:21 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

void	free_map(t_map *map)
{
	free_list(map->list);
	free_two_dim_arr((void *)map->wall);
	free_two_dim_arr((void *)map->map);
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
