/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:58:48 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/04 17:14:52 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

char	*ft_ftrim(char *ptr1, char *ptr2, char *c_s1, char *set)
{
	while (*ptr1 != '\0')
	{
		if (ft_strchr(set, (int )*ptr1) != NULL)
		{
			ptr1++;
			if (*ptr1 == '\0')
			{
				ptr1 = ft_strdup(ptr1);
				if (ptr1 == NULL)
					return (NULL);
				free(c_s1);
				return (ptr1);
			}
		}
		else
			break ;
	}
	while (ft_strchr(set, (int )*ptr2--) != NULL)
		*(ptr2 + 1) = '\0';
	ptr1 = ft_strdup(ptr1);
	if (ptr1 == NULL)
		return (NULL);
	free(c_s1);
	return (ptr1);
}

char	*ft_strtrim(char *s, char const *set)
{
	char	*c_s1;
	char	*ptr1;
	char	*ptr2;

	if (!s || !set)
		return (NULL);
	c_s1 = ft_strdup(s);
	if (c_s1 == NULL)
		return (NULL);
	ptr1 = c_s1;
	ptr2 = &c_s1[ft_strlen(c_s1)];
	free(s);
	return (ft_ftrim(ptr1, ptr2, c_s1, (char *)set));
}
