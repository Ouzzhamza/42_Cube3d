/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:12:07 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/27 15:46:14 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

void	get_dimension_of_map(t_map *map, int *width, int *height)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->map[0][j])
		j++;
	*width = j;
	while (map->map[i])
		i++;
	*height = i;
	map->x_scall = WIN_WIDTH / (WIN_WIDTH / 2);
	map->y_scall = WIN_HEIGHT / (WIN_HEIGHT / 2);
}

int	is_identifire(char *str, t_map *map)
{
	char	**line;

	if (!ft_isprint(str[0]) || !ft_isprint(str[ft_strlen(str)- 1]))
		return (0);
	line = ft_split(str, ' ');
	if (!line[1] || !line[0])
		return (free_table(line), 0);
	else if (!ft_strcmp(FLOOR, line[0]) && map->floor == -1)
	{
		map->floor = 0;
		rgb_to_int(&map->floor, str, map);
	}
	else if (!ft_strcmp(CEILING, line[0]) && map->ceiling == -1)
	{
		map->ceiling = 0;
		rgb_to_int(&map->ceiling, str, map);
	}
	else if (!valid_wall_image(line, map))
		return (free_table(line), 0);
	free(str);
	return (1);
}

int	is_number(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+') && ft_strlen(num) > 1)
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
