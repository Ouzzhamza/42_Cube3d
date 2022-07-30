/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/30 20:20:13 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"


int	cheack_line(char *line, t_map *map)
{
	int i;
	i = 0;
	is_identifire(line, map);
	//is_map(char *line, t_map *map);
	return (1);	
}

int	read_map(int ac, char **av)
{
	char		*line;
	int			fd;
	t_map *map;
	map = (t_map *) malloc (sizeof(t_map));
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
		//printf("%c\n", line[0]);
		// if(!ft_strncmp (&line[0], "\t", 1))
		// {
		// 	printf("%s", line);
		// 	//printf("%s", line);
		// }
		if (!cheack_line(line, map))
			ft_error(MAP);
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
	//atexit(checkLeaks);
	read_map(ac, av);
}
