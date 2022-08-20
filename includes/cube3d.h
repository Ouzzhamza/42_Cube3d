/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:03:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/20 10:36:36 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "structs.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>


//^ MACROS 
# define ARG "Wrong number of arguments\n"
# define MAP "Invalid map\n"
# define RGB "Invalid color value\n"
# define NORTH "NO"
# define EAST  "EA"
# define WEST  "WE"
# define SOUTH "SO"
# define FLOOR "F"
# define CEILING "C"

//^ CUBE3D_UTILES
int         ft_atoi(const char *str);
char	    *get_next_line(int fd);
int	        ft_strlen(const char *str);
char	    *ft_strdup(const char *str);
char	    *ft_strchr(char *s, int c);
char	    *ft_strjoin(char *s1, char *s2);
void	    ft_error(char *str);
void	    ft_putstr(char *str);
char	    **ft_split(char *s, char c);
int	        ft_lstsize(t_list *lst);
int	        ft_strncmp(const char *s1, const char *s2, size_t n);
t_list      *ft_lstlast(t_list *lst);
t_list	    *ft_lstnew(void *content);
void	    ft_lstadd_back(t_list **lst, t_list *new);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);
char        *ft_strtrim(char *s, char const *set);
void	    *ft_memset(void *b, int c, size_t n);
int         ft_strcmp(char *s1, char *s2);
char	    *ft_strnstr(const char *haystack, const char *needle, size_t len);
int	        ft_isprint(int c);

//^ PARCING_UTILES
int         is_identifire(char *str, t_map *map);
int         a_wall(char *str, t_map *map);
void	    free_table(char **table);
void        free_all(t_map *map);
void        set_to_zero(t_map *map, t_list *list);
int         empty_line(char *str);
int         special_strlen(char *str);
void        list_to_array(t_map *map);
char        *special_dupe(char *s1, int size);
int         map_file_name(char *str);

//^ MINIMAP PARSING
int     check_vertical(char **map, int x, int y);
int     check_horizontal(char **map, int x, int y);
int     check_item_valid(char **map, int x, int y);
int     parse_map(char **map);
int     render_player(t_data *data, int x, int y, int color);
int     parse_minimap(t_map *map);
void    draw_minimap(t_data *data, char **map);
void    get_dimension_of_map(t_map *map, int *width, int *height);

//^ RAYCASTING
// t_raycast   *raycast_init(void);
t_point	get_player_pos(char **map);
double      convert_degree_to_radian(double degree);
void        drawline(t_data *data, int x0, int y0, int x1, int y1);
void        my_mlx_put_pixel(t_data *data, int x, int y, int color);
t_player    *player_data_init(t_map *map);
double      player_angle(char direction);
t_raycast   *raycast_data_init(t_data *data, t_map *map, t_player *player);
int         handle_player_move(int key, void *data);
int         close_win(int key, void *param);
int         red_cross(void *param);
int         trace_rays(t_raycast *raycast);

// ^Free Functions
void	free_list(t_list *list);
void	free_two_dim_arr(char **arr);
void	free_map(t_map *map);

double  get_horizontal_intersection(t_raycast *raycast, double angle);
double  get_vertical_intersection(t_raycast *raycast, double angle);
double  get_intersection(t_raycast *raycast, double angle);
int     ray_casting(t_raycast *raycast);
void	init_tab(double *tab, int size);

void move_forward(t_raycast *raycast);
void retreat(t_raycast *raycast);
void move_right(t_raycast *raycast);
void move_left(t_raycast *raycast);
void redraw(t_raycast *raycast);
void hooks(t_raycast *raycast);
int	valid_move(t_raycast *raycast, int type);

t_point	first_intersec_horiz(t_raycast *raycast, double angle);
t_point xy_steps_horiz(double angle);
t_point	first_intersec_vertic(t_raycast *raycast, double angle);
t_point xy_steps_vertic(double angle);
double	calculate_ray_distance(t_point player_pos, t_point wall_pos);
double	normlize_angle(double angle);
bool ft_is_ray_right(double angle);
bool ft_is_ray_up(double angle);
double	calculate_wall_projection(t_raycast *raycast, double dist_wall);
void	free_raycast(t_raycast *raycast);
int	draw_wall(t_raycast *raycast, int x_start, double wall_height);
void	render_image_color(t_raycast *raycast, int color, int y_start);
// double	calculate_ray_distance(t_point player_pos, t_point wall_pos);

int ft_grb(int t, int r, int g, int b);
#endif