/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/04 19:26:29 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"


int	cheack_line(char *line, t_map *map)
{
	int i;
	t_list *new;

	i = 0;
	line = ft_strtrim(line, "\n");
	if (line[0] != '\0' && !is_identifire(line, map))
	{
		if (!a_wall(line, map))
			ft_error(MAP);
		if(map->longest)
		{
			new = ft_lstnew(line);
			ft_lstadd_back(&(map->list), new);

		}
	}
	return (1);
}

int	read_map(int ac, char **av)
{
	char		*line;
	int			fd;
	t_map		*map;
	
	map = (t_map *) malloc (sizeof(t_map));
	map->list = (t_list *) malloc (sizeof(t_list));
	set_to_zero(map);
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
			cheack_line(ft_strdup(line), map);
		free(line);
	}
	if (!map->identifier)
		ft_error(MAP);
	list_to_array(map);
	int i = 0;
	while(map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	free(map); // ! need to free the map struct
	return (0);
}

// void checkLeaks()
// {
// 	system("leaks cube3d");
// }

int	main(int ac, char **av)
{
	//atexit(checkLeaks);
	read_map(ac, av);
}
