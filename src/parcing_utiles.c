/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:21:30 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/01 18:59:31 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"

int a_wall(char *str, t_map *map)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' ' || str[i] == '\t')
			;
		else if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			if (map->ground_plan == 0)
				map->ground_plan++;
			else
				return (0);
		}
		else if (!str && map->building == 1)
			return(0);
		i++;
	}
	return(1);
}

void rgb_to_int(int rgb, char *str, t_map *map)
{
	char **line;
	char **ptr;
	int	byte;
	int i;

	byte = 65536;
	i = -1;
	line = ft_split(str, ' ');
	ptr = line;
	line = ft_split(line[1], ',');
	while(line[++i])
	{
		if (ft_atoi(line[i]) > 255 || ft_atoi(line[i]) < 0)
			ft_error(RGB);
		else
		{
			rgb = rgb + ft_atoi(line[i]) * byte;
			byte = byte / 256;
		}
	}
	map->identifier++;
	free_table(ptr);
	free_table(line);
}

int is_identifire(char *str, t_map *map)
{   
	char **line;

	line = ft_split(str, ' ');
	if(!ft_strcmp(NORTH, line[0]) || !ft_strcmp(EAST, line[0]) || \
	!ft_strcmp(WEST, line[0]) || !ft_strcmp(SOUTH, line[0]))
	{
		if (open(ft_strtrim(line[1], "\n"), O_RDONLY) == -1)
			ft_error(MAP);
		else
			map->identifier++;
		free_table(line);
	}
	else if (!ft_strcmp(FLOOR, line[0]))
		rgb_to_int(map->floor, str, map);
	else if (!ft_strcmp(CEILING, line[0])) 
		rgb_to_int(map->ceiling, str, map);
	else
		return(0);
	return(1);
}
