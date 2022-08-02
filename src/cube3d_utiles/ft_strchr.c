/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:02:42 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/02 17:03:00 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;

	b = ((char *) s);
	i = 0;
	a = (char) c;
	if (c == 0)
		return (b + ft_strlen(b));
	while (b[i])
	{
		if (b[i] == a)
			return (&b[i]);
		i++;
	}
	return (NULL);
}