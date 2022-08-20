/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:23:50 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/20 10:16:42 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1020
# define CUB_SIZE	32
# define NO 0
# define SO 3
# define WE 2
# define EA 1

typedef struct s_list
{
	char 	*line;
	struct 	s_list *next; 
} t_list;

typedef struct map
{
	char 		**map;
	char 		*wall[5];
	char		player;
	int			ceiling;
	int			floor;
	void		*mlx;
	int			identifier;
	int 		longest;
	int			map_width;
	int			map_height;
	t_list 		*list;
} t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
} t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
} t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;
}t_rect;

typedef struct s_point
{
	double	x;
	double	y;
} t_point;

typedef struct s_player
{
	t_point	map_pos;
	double	angle;
	double	speed;
} t_player;

typedef struct	s_raycast
{
	t_data		*data;
	t_player	*player;
	t_map		*map;
	double		dis_plane;
	double		angle;
	double		increment_angle;
	double		height_proj;
	double		half_width;
	double		centre_height;
	double		width_limit;
	double		height_limit;
	t_img		*textures;
} t_raycast;

#endif