/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:39:35 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/28 14:57:41 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

int	ft_is_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != 32)
			return (1);
		i++;
	}
	return (0);
}
