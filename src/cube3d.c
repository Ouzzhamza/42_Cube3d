/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/08 18:20:20 by houazzan         ###   ########.fr       */
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

t_map	*read_map(int ac, char **av)
{
	char		*line;
	t_map		*map;
	int			fd;

	map = (t_map *) malloc (sizeof(t_map));
	map->list = (t_list *) malloc (sizeof(t_list));
	set_to_zero(map, map->list);
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
	if (map->identifier != 6)
		ft_error(MAP);

	list_to_array(map);
	return (map);
}

void	mlx_data_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error("mlx_ptre Error!\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUBE3D");
	if (!data->win_ptr)
		ft_error("mlx_win Error!\n");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.mlx_img)
		ft_error("mlx_img Error!\n");
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
}


int	main(int ac, char **av)
{
	t_map	*map;
	t_data	data;

	map = read_map(ac, av);
	if (parse_map(map->map))
	{
		mlx_data_init(&data);
		draw_minimap(&data, map->map);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
