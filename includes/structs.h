/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:23:50 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/27 17:00:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WIN_WIDTH  850
# define WIN_HEIGHT 600
# define CUB_SIZE 20
# define MINI_HEIGHT 150
# define MINI_WIDTH 350
# define MIMPH_CENTER 75
# define MIMPW_CENTER 175
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
	int			x_scall;
	int			y_scall;
	int			identifier;
	int 		longest;
	int			map_width;
	int			map_height;
	void		*mlx;
	t_list 		*list;
} t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		*addr;
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
	t_point minimap_pos;
	double	angle;
	double	speed;
	int		advance;
	int		retreat;
	int		left;
	int		right;
	int		l_rotate;
	int		r_rotate;
	int		exit;
} t_player;

typedef struct s_proj
{
	double		x_offset;
	double		y_offset;
	int			draw_start;
	int			draw_end;
	int			y;
	int			color;
	int			dist_from_top;
}t_proj;

typedef struct s_bresn
{
	int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int e2;
}t_bresn;

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
	int			inters_type;
	double			*x;
	double			*y;
	double			Dx;
	double			Dy;
	double		wall_height;
	t_img		textures[4];
} t_raycast;

#endif