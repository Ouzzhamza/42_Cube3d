/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parcing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:12:07 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 23:40:00 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
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


int	is_number(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+') && ft_strlen(num) > 1)
		i++;
	while (num[i])
	{
		if ((num[i] < '0' || num[i] > '9') && num[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}


int	is_a_wall(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (!ft_is_space(line) && !map->list)
		return(1);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			;
		else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
		{
			if (map->player == '\0')
				map->player = line[i];
			else
				return (0);
		}
		else
			return (0);
		i++;
	}
	if (map->longest < special_strlen(line))
		map->longest = special_strlen(line);
	if (map->identifier != 6 || !put_on_list(line, map))
		return(0);
	return (1);
}

int	texture(char **ident, t_map *map)
{
	if ((!ft_strcmp(ident[0], NORTH) && arlen(ident) != 2) \
	|| (!ft_strcmp(ident[0], SOUTH) && arlen(ident) != 2) \
	|| (!ft_strcmp(ident[0], WEST) && arlen(ident) != 2) \
	|| (!ft_strcmp(ident[0], EAST) && arlen(ident) != 2) \
	|| open(ident[1], O_RDONLY) == -1 \
	|| ft_strlen(ft_strnstr(ident[1],".xpm", ft_strlen(ident[1]))) != 4)
		return (0);
	else if (!ft_strcmp(NORTH, ident[0]) && !map->wall[0])
		map->wall[0] = ft_strdup(ident[1]);
	else if (!ft_strcmp(EAST, ident[0]) && !map->wall[1])
		map->wall[1] = ft_strdup(ident[1]);
	else if (!ft_strcmp(WEST, ident[0]) && !map->wall[2])
		map->wall[2] = ft_strdup(ident[1]);
	else if (!ft_strcmp(SOUTH, ident[0]) && !map->wall[3])
		map->wall[3] = ft_strdup(ident[1]);
	else
		return (0);
	map->identifier++;
	free_table(ident);
	return (1);
}

int	color(char **ident, t_map *map)
{
	char	**ptr;

	if ((!ft_strcmp(ident[0], CEILING) && arlen(ident) != 2) || \
	(!ft_strcmp(ident[0], FLOOR) && arlen(ident) != 2) || arlen(ident) != 2)
		return(0);
	if (ident[1][0] < '0' ||  ident[1][0] > '9')
		return(0);
	if (ident[1][ft_strlen(ident[1]) - 1] < '0' || ident[1][ft_strlen(ident[1]) - 1] > '9')
		return(0);
	ptr = ft_split(ident[1], ',');
	if (arlen(ptr) != 3)
		return(free_table(ptr), 0);
	if (ident[0][0] == 'C')
		map->ceiling = rgb_value(ptr);
	else
		map->floor = rgb_value(ptr);
	map->identifier++;
	if (map->ceiling == -2 || map->floor == -2)
		return(free_table(ptr), 0);
	free_table(ptr);
	return(1);
}
