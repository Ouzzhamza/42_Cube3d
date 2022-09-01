/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:21:30 by houazzan          #+#    #+#             */
/*   Updated: 2022/09/01 17:59:40 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

int	put_on_list(char *line, t_map *map)
{
	t_list *node;

	node = ft_lstnew(line);
	ft_lstadd_back(&map->list, node);
	if (ft_is_space(ft_lstlast(map->list)->line) \
	&& !ft_is_space(ft_lstlast(map->list)->prev->line))
		return(0);
	return(1);
}


void	list_to_array(t_map *map)
{
	int		i;
	int		number;
	t_list	*ptr;

	number = ft_lstsize(map->list);
	ptr = map->list;
	i = 0;
	if (!map->player)
		ft_error("Player does not exist on map", map);
	map->map = (char **) malloc (number * sizeof(char *) + 1);
	if (!map->map)
		exit(0);
	while (ptr)
	{
		map->map[i] = special_dupe(ptr->line, map->longest);
		i++;
		ptr = ptr->next;
	}
	map->map[i] = NULL;
}

int rgb_value(char **ptr)
{
	int i;
	int	byte;
	int rgb;

	byte = 65536;
	i = -1;
	rgb = 0;
	while (ptr[++i])
	{
		if (is_number(ptr[i]) || ft_atoi(ptr[i]) > 255 || ft_atoi(ptr[i]) < 0)
			return(-2);
		else
		{
			rgb = rgb + ft_atoi(ptr[i]) * byte;
			byte = byte / 256;
		}
	}
	return(free_table(ptr), rgb);
}


int arlen(char **ident)
{
	int i;

	i = 0;
	while (ident[i])
		i++;
	return(i);
}