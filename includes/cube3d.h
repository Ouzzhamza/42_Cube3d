/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:03:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/05 13:14:27 by houazzan         ###   ########.fr       */
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
# define WIN_WIDTH 1500
# define WIN_HEIGHT 400

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

#endif