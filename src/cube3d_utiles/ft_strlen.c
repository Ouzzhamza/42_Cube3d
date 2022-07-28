/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:02:58 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/28 20:07:16 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

int	ft_strlen(const char *str)
{
	int	i;

    i = 0;
	if (!str)
		return(0);
	while (str[i])
		i++;
	return (i); 
}