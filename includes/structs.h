/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:23:50 by houazzan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/22 23:07:27 by houazzan         ###   ########.fr       */
=======
/*   Updated: 2022/08/22 21:13:37 by mmoumni          ###   ########.fr       */
>>>>>>> ddb35a5b71d33c1086019ae761a42c65c76b8924
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

<<<<<<< HEAD
# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define CUB_SIZE	32
=======
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1020
# define CUB_SIZE	16
# define NO 0
# define SO 3
# define WE 2
# define EA 1
>>>>>>> ddb35a5b71d33c1086019ae761a42c65c76b8924

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
	int			inters_type;
	t_img		*textures;
} t_raycast;

#endif