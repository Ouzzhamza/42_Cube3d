/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utiles1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:04:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/28 15:15:03 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

int	special_strlen(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (str[i - 1] == ' ')
		i--;
	return (i);
}

void	set_to_zero(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->ceiling = -1;
	map->floor = -1;
}

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	*special_dupe(char *s1, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	map_file_name(char *str)
{
	if (!ft_strnstr(str, ".cub", ft_strlen(str)))
		return (0);
	if (ft_strcmp(ft_strnstr(str, ".cub", ft_strlen(str)), ".cub"))
		return (0);
	return (1);
}
