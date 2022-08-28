/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/28 15:34:16 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"

int	cheack_line(char *line, t_map *map)
{
	int		i;
	t_list	*new;

	i = 0;
	line = ft_strtrim(line, "\n");
	if (!is_identifire(line, map))
	{
		if (!a_wall(line, map))
			ft_error(MAP, map);
		if (map->longest)
		{
			map->map_start = 1;
			new = ft_lstnew(line);
			ft_lstadd_back(&(map->list), new);
			if (ft_is_space(new->line) && !ft_is_space(new->prev->line))
				ft_error(MAP, map);
		}
		if (!ft_is_space(line))
			free(line);
	}
	return (1);
}

t_map	*read_map(int ac, char **av)
{
	char		*line;
	t_map		*map;
	int			fd;

	map = (t_map *) malloc (sizeof(t_map));
	map->list = NULL;
	set_to_zero(map);
	if (ac != 2)
		ft_error(ARG, map);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !(map_file_name(av[1])))
		ft_error(MAP, map);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		cheack_line(ft_strdup(line), map);
		free(line);
	}
	if (map->identifier != 6)
		ft_error(MAP, map);
	list_to_array(map);
	return (map);
}

void	mlx_data_init(t_data *data, t_map *map)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error("mlx_ptre Error!\n", map);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, "CUBE3D");
	if (!data->win_ptr)
		ft_error("mlx_win Error!\n", map);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.mlx_img)
		ft_error("mlx_img Error!\n", map);
	data->img.addr = (int *)mlx_get_data_addr(data->img.mlx_img, \
	&data->img.bpp, &data->img.line_len, &data->img.endian);
}

int	trace_rays(t_raycast *raycast, t_rect *rectangle)
{
	t_intpo	p0;
	t_intpo	p1;

	p0.x = rectangle->x;
	p0.y = rectangle->y;
	p1.x = p0.x + cos(raycast->player->angle) * 30;
	p1.y = p0.y + sin(raycast->player->angle) * 30;
	drawline(raycast, p0, p1);
	return (1);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_data		data;
	t_player	*player;
	t_raycast	*raycast;

	map = read_map(ac, av);
	get_dimension_of_map(map, &map->map_width, &map->map_height);
	if (parse_map(map))
	{
		mlx_data_init(&data, map);
		player = player_data_init(map);
		raycast = raycast_data_init(&data, map, player);
		load_xpm_files(raycast);
		render_image_color(raycast, raycast->map->ceiling, 0);
		render_image_color(raycast, raycast->map->floor, WIN_HEIGHT / 2);
		ray_casting(raycast);
		draw_minimap(raycast, map->map);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.img.mlx_img, 0, 0);
		hooks(raycast);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
