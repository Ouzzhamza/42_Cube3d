/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:52:42 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/02 18:21:25 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (len == 0 && needle[i] != '\0')
		return (NULL);
	if (needle[i] == '\0' || len == '\0')
		return ((char *)haystack);
	if (len == 1 && haystack[0] == needle[0])
		return ((char *)haystack);
	while (i < len - 1 && haystack[i])
	{
		j = 0;
		while ((haystack[i + j] == needle[j] || needle[j] == '\0'))
		{
			if (needle[j] == '\0' && i + j <= len)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}