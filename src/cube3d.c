/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/28 20:26:04 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"

int	cheack_line(char *line)
{
	int i;
	char **line_table;

	i = 0;
	line_table = ft_split(line, ' ');
	if (ft_str)
	return (0);
	
}

int	read_map(int ac, char **av)
{
	char		*line;
	int			fd;
	//t_map_lines *map;

	if (ac != 2)
		ft_error(ARG);
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!cheack_line(line))
			ft_error(MAP);
	}
}

int	main(int ac, char **av)
{
	read_map(ac, av);
}
