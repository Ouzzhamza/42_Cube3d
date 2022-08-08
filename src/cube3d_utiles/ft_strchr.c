/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:02:42 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/08 14:36:52 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}
