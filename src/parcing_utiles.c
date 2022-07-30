/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:21:30 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/30 20:39:35 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"

// void is_map(char *str, t_map *map)
// {
// 	int i;

// 	i = 0;	
// 	while (str[i])
// 	{
// 		if(str[i] != "\t" || str[i] != " " || str[i] != "1" || str[i] != "0" \
// 			str[i] != "N" || str[i] != "S" || str[i] != "E" || str[i] != "W")
// 	}
// }

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
	if(!ft_strncmp(NORTH, line[0], 2) || !ft_strncmp(EAST, line[0], 2) || \
	!ft_strncmp(WEST, line[0], 2) || !ft_strncmp(SOUTH, line[0], 2))
	{
		printf("%s\n", line[0]);
		if (open(line[1], O_RDONLY, 0444))
			map->identifier++;
		free_table(line);
	}
	else if (!ft_strncmp(FLOOR, str, 1))
		rgb_to_int(map->floor, str, map);
	else if (!ft_strncmp(CEILING, str, 1)) 
		rgb_to_int(map->ceiling, str, map);
	return(1);
}
