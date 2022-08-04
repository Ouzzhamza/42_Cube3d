/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:23:50 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/04 15:41:26 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif


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
	int			identifier;
	int 		longest;
	t_list 		*list;
} t_map;

#endif