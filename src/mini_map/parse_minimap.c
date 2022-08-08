/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:10:41 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/08 13:31:19 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

int	check_vertical(char **map, int x, int y)
{
	int	i;
	int	j;

	i = x - 1;
	j = y;
	if (i >= 0)
	{
		if (map[i][j] == ' ')
			return (1);
	}
	else
		return (1);
	i = x + 1;
	j = y;
	if (map[i])
	{
		if (map[i][j] == ' ')
			return (1);
	}
	else
		return (1);
	return (0);
}

int	check_horizontal(char **map, int x, int y)
{
	int	i;
	int	j;

	i = x;
	j = y - 1;
	if (j >= 0)
	{
		if (map[i][j] == ' ')
			return (1);
	}
	else
		return (1);
	i = x;
	j = y + 1;
	if (map[i][j] != '\0')
	{
		if (map[i][j] == ' ')
			return (1);
	}
	else
		return (1);
	return (0);
}

int	check_item_valid(char **map, int x, int y)
{
	if (check_vertical(map, x, y))
		return (1);
	if (check_horizontal(map, x, y))
		return (1);
	return (0);
}

int	parse_map(char **map)
{
	int	i;
	int	j;
	int	validation;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'W' || map[i][j] == 'N'
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				validation = check_item_valid(map, i, j);
				if (validation)
					ft_error(MAP);
			}
			j++;
		}
		i++;
	}
	return (1);
}
