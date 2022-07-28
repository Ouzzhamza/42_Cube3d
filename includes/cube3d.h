/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:03:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/28 20:07:43 by houazzan         ###   ########.fr       */
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

//^ MACROS 
# define ARG "Wrong number of arguments"
# define MAP "Invalid map"

char	    *get_next_line(int fd);
int	        ft_strlen(const char *str);
char	    *ft_strdup(char *str);
char	    *ft_strchr(char *s, int c);
char	    *ft_strjoin(char *s1, char *s2);
void	    ft_error(char *str);
void	    ft_putstr(char *str);
char	    **ft_split(char const *s, char c);
int	        ft_lstsize(t_map_lines *lst);
t_map_lines *ft_lstlast(t_map_lines *lst);
t_map_lines	*ft_lstnew(void *content);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif