/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:24:02 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/28 14:34:11 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
		new->next = NULL;
	}
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
		new->prev = last_node;
		new->next = NULL;
	}
}
