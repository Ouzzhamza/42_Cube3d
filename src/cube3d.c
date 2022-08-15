/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/15 12:59:29 by mmoumni          ###   ########.fr       */
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

int	trace_rays(t_raycast *raycast)
{
	int		i;
	double	angle_iter;
	t_point ray;

	i = 0;
	angle_iter = raycast->player->angle - (M_PI / 6);
	while (i < WIN_WIDTH)
	{
		ray.x = raycast->player->map_pos.x + raycast->dis_plane * cos(angle_iter);
		ray.y = raycast->player->map_pos.y + raycast->dis_plane * sin(angle_iter);
		drawline(raycast->data, raycast->player->map_pos.x, raycast->player->map_pos.y, ray.x, ray.y);
		angle_iter += raycast->increment_angle;
		i++;
	}
	return (1);
}

void	print_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			printf("%c ", map->map[i][j]);
			j++;
		}
		// printf("\n");
		i++;
	}
	printf("hello\n");
}

void	print_rays(t_raycast *ray_casting)
{
	int i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		printf("cord:%d = Dis:%f",i,ray_casting->rays[i]);
		i++;
	}
}


int	main(int ac, char **av)
{
	t_map		*map;
	t_data		data;
	t_player 	*player;
	t_raycast	*raycast;

	map = read_map(ac, av);
	if (parse_map(map->map))
	{
		
		mlx_data_init(&data);
		player = player_data_init(map);
		draw_minimap(&data, map->map);
		raycast = raycast_data_init(&data, map, player);
		// printf("%f -- %f\n", raycast->player->map_pos.x / CUB_SIZE, raycast->player->map_pos.y / CUB_SIZE);
		// printf("%f -- %f\n",player.map_pos.x, player.map_pos.y);
		// render_player(&data, player.map_pos.x, player.map_pos.y, 0x00FF00);
		// trace_rays(raycast);
		// printf("Here\n");
		ray_casting(raycast);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
		mlx_hook(data.win_ptr, 17, 0, red_cross, &raycast);
		// mlx_hook(data.win_ptr, 2, 0, handle_player_move, &raycast);
		mlx_key_hook(data.win_ptr, close_win, &raycast);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}