/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/29 19:01:47 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"


int	cheack_line(char *line, t_map *map)
{
	int i;
	char **line_table;

	i = 0;
	line_table = ft_split(line, ' ');
	if (!identifire(line_table, map))
	{
		puts("hello");
		ft_error(MAP);
	}
	return (1);	
}

int	read_map(int ac, char **av)
{
	char		*line;
	int			fd;
	t_map *map;

	map = NULL;
	if (ac != 2)
		ft_error(ARG);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(MAP);
	while (1)
	{
		line = get_next_line(fd);
		if (!cheack_line(line, map))
			ft_error(MAP);
		printf("%s\n", line);
		free(line);
	}
}

int	main(int ac, char **av)
{
	read_map(ac, av);
}
