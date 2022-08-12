/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 08:29:23 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/12 08:35:22 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cube3d.h"
# include "../../includes/structs.h"

void	free_map(t_map *map)
{
	free(map->map);
	free_list(map->list);
}

void	free_two_dim_arr(char **arr)
{
	int i;

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