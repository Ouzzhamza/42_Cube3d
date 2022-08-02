/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/02 21:40:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"


int	cheack_line(char *line, t_map *map)
{
	int i;
	i = 0;
	line = ft_strtrim(ft_strtrim(line, " "), "\n");
	if(!is_identifire(line, map))
		ft_error(MAP);
	return (1);	
}

int	read_map(int ac, char **av)
{
	char		*line;
	int			fd;
	t_map		*map;
	
	map = (t_map *) malloc (sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	if (ac != 2)
		ft_error(ARG);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(MAP);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line[0] != '\n')
			cheack_line(line, map);
		free(line);
	}
	free(map); // ! need to free the map struct
	return (0);
}
void checkLeaks()
{
	system("leaks cube3d");
}

int	main(int ac, char **av)
{
	read_map(ac, av);
}
