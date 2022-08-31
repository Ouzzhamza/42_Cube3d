/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:15:18 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/31 19:54:47 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc (sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr ->line = ft_strdup(content);
	ptr ->next = NULL;
	ptr ->prev = ptr;
	return (ptr);
}
