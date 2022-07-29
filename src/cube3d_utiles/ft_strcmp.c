/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 08:18:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/07/29 08:20:12 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int 			i;
	unsigned char	*c_s1;
	unsigned char	*c_s2;

	i = 0;
	c_s1 = (unsigned char *)s1;
	c_s2 = (unsigned char *)s2;
	while (c_s1[i] && c_s2[i])
	{
		if (c_s1[i] != c_s2[i])
			return (c_s1[i] - c_s2[i]);
		i++;
	}
	return (c_s1[i] - c_s2[i]);
}