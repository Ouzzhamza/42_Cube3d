/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:15:18 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/28 18:49:48 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/structs.h"
#include "../../includes/cube3d.h"


t_map_lines	*ft_lstnew(void *content)
{
	t_map_lines	*ptr;

	ptr = (t_map_lines *)malloc (sizeof(t_map_lines));
	if (ptr == NULL)
		return (NULL);
	ptr ->line = content;
	ptr ->next = NULL;
	return (ptr);
}