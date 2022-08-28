/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:21:30 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/28 14:27:49 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

void	list_to_array(t_map *map)
{
	int		i;
	int		number;
	t_list	*ptr;

	number = ft_lstsize(map->list);
	ptr = map->list;
	i = 0;
	map->map = (char **) malloc (map->longest * sizeof(char *) + 1);
	while (ptr)
	{
		map->map[i] = special_dupe(ptr->line, map->longest);
		i++;
		ptr = ptr->next;
	}
	map->map[i] = NULL;
}

int	a_wall(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' ')
			;
		else if (str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'W' || str[i] == 'E')
		{
			if (map->player == '\0')
				map->player = str[i];
			else
				return (0);
		}
		else
			return (0);
		i++;
	}
	if (map->longest < special_strlen(str))
		map->longest = special_strlen(str);
	return (1);
}

void	rgb_to_int(int *rgb, char *str, t_map *map)
{
	char	**line;
	char	**ptr;
	int		byte;
	int		i;

	byte = 65536;
	i = -1;
	line = ft_split(str, ' ');
	ptr = ft_split(line[1], ',');
	while (ptr[++i])
	{
		if (is_number(ptr[i]) || ft_atoi(ptr[i]) > 255
			|| ft_atoi(ptr[i]) < 0)
			ft_error(RGB, map);
		else
		{
			*rgb = *rgb + ft_atoi(ptr[i]) * byte;
			byte = byte / 256;
		}
	}
	if (i != 3)
		ft_error(RGB, map);
	map->identifier++;
	free_table(ptr);
	free_table(line);
}

int	valid_wall_image(char **line, t_map *map)
{
	if (open(line[1], O_RDONLY) == -1 || ft_strlen(ft_strnstr(line[1], \
		".xpm", ft_strlen(line[1]))) != 4)
		return (0);
	else if (!ft_strcmp(NORTH, line[0]) && !map->wall[0])
		map->wall[0] = ft_strdup(line[1]);
	else if (!ft_strcmp(EAST, line[0]) && !map->wall[1])
		map->wall[1] = ft_strdup(line[1]);
	else if (!ft_strcmp(WEST, line[0]))
		map->wall[2] = ft_strdup(line[1]);
	else if (!ft_strcmp(SOUTH, line[0]) && !map->wall[3])
		map->wall[3] = ft_strdup(line[1]);
	else
		return (0);
	map->identifier++;
	free_table(line);
	return (1);
}
