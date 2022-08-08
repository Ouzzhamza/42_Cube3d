/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:23:50 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/08 11:50:25 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define WIN_WIDTH 1500
# define WIN_HEIGHT 400
# define CUB_SIZE	64

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
	t_list 		*list;
} t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
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

typedef struct	s_raycast
{
	int		dim_proj_plane;
	int		cent_proj;
	double	dis_proj;
	double	angle;
} t_raycast;

#endif