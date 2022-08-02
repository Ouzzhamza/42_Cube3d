/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:21:30 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/02 21:47:14 by houazzan         ###   ########.fr       */
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
			if (map->player == '\0')
				map->player = str[i];
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
	if(i != 3)
		ft_error(RGB);
	map->identifier++;
	free_table(ptr);
	free_table(line);
}

int valid_wall_image(char **line, t_map *map)
{
	if (open(line[1], O_RDONLY) == -1 || ft_strlen(ft_strnstr(line[1], \
		".xpm", ft_strlen(line[1]))) != 4)
		ft_error(MAP);	
	else if (!ft_strcmp(NORTH, line[0]) && !map->wall[0])
		map->wall[0] = ft_strdup(line[1]);
	else if (!ft_strcmp(EAST, line[0]) && !map->wall[1])
		map->wall[1] = ft_strdup(line[1]);
	else if (!ft_strcmp(WEST, line[0]) && !map->wall[2])
		map->wall[2] = ft_strdup(line[1]);
	else if (!ft_strcmp(SOUTH, line[0]) && !map->wall[3])
		map->wall[3] = ft_strdup(line[1]);
	else
		return(0);
	map->identifier++;
	return(1);
}
int is_identifire(char *str, t_map *map)
{   
	char **line;
	(void)(map);
	
	if(!ft_isprint(str[0]) || !ft_isprint(str[ft_strlen(str) - 1]))
		ft_error(MAP); 
	line = ft_split(str, ' ');
	if (!ft_strcmp(FLOOR, line[0]) && )
		rgb_to_int(map->floor, str, map);
	else if (!ft_strcmp(CEILING, line[0])) 
		rgb_to_int(map->ceiling, str, map);
	else if (line[1])
		if(!valid_wall_image(line, map))
			return(0);
	return(1);
}
