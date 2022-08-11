/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:02:31 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/11 12:04:13 by mmoumni          ###   ########.fr       */
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

int	raycast_init(t_raycast *raycast)
{
	raycast->dim_proj_plane = WIN_HEIGHT * WIN_WIDTH;
	raycast->cent_proj = (t_point) {WIN_HEIGHT / 2, WIN_WIDTH / 2};
	raycast->dis_proj = (WIN_WIDTH / 2) / tan(M_1_PI / 6);
	raycast->angle = M_1_PI / 3;
	raycast->incrment_angle = (M_1_PI / 3) / WIN_WIDTH;
	return (1);
}

void trace_rays(t_data *data, t_point player_pos, t_raycast *raycast)
{
	int i;
	t_point a;
	double angle;

	i = 0;
	angle = -(M_PI / 6);
	// raycast->player_angle = 0;
	// player_pos.x = (player_pos.x) * cos(raycast->player_angle) - (player_pos.y) * sin(raycast->player_angle);
	// player_pos.y = (player_pos.x) * sin(raycast->player_angle) + (player_pos.y ) * cos(raycast->player_angle);
	// angle += raycast->player_angle;
	while (i < WIN_WIDTH)
	{
		// a.x = player_pos.x;
		// a.y = player_pos.y;
		a.x = (player_pos.x + 50) * cos(angle) - (player_pos.y + 50) * sin(angle);
		a.y = (player_pos.x + 50) * sin(angle) + (player_pos.y + 50) * cos(angle);
		drawline(data, (int)player_pos.x, (int)player_pos.y, (int)a.x, (int)a.y);
		angle += raycast->incrment_angle;
		i++;
	}	
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_data		data;
	// t_raycast	raycast;
	t_point		player_pos;
	t_point		a;

	map = read_map(ac, av);
	if (parse_map(map->map))
	{
		mlx_data_init(&data);
		player_pos = draw_minimap(&data, map->map);
		// printf("%f - %f\n",player_pos.x, player_pos.y);
		a.x = player_pos.x * cos((2 * M_PI)/3 ) - (player_pos.y + 100) * sin((2 * M_PI)/3 );
		a.y = player_pos.x * sin((2 * M_PI)/3 ) + (player_pos.y + 100) * cos((2 * M_PI)/3 );
		drawline(&data, player_pos.x, player_pos.y, a.x, a.y);
		// raycast_init(&raycast);
		// trace_rays(&data, player_pos, &raycast);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
		mlx_loop(data.mlx_ptr);
	}
	// for (int i = 0; map->map[i]; i++)
	// {
	// 	for (int j = 0; map->map[i][j]; j++)
	// 	{
	// 		printf("%c ", map->map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return (0);
}
