/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:44:29 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/27 16:45:09 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cube3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			strlen;
	char			*str;

	if (s)
	{
		strlen = ft_strlen(s);
		if (start >= strlen)
			return (ft_strdup(""));
		if (len >= strlen)
			len = strlen;
		str = (char *)malloc(len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (s[start] && i < len)
		{
			str[i++] = s[start];
			start++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
