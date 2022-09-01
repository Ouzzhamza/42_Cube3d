/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fa_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:06:25 by houazzan          #+#    #+#             */
/*   Updated: 2022/09/01 16:31:57 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"
#include "../../includes/structs.h"

int first_word(char *str, char limit)
{
	int i;

	i = 0;
	while(str[i] != limit && str[i])
		i++;
	return(i);
}



char	**ft_fa_split(char *s, char c)
{
	int		i;
	char	**str;
	int		rest;
	int		len;

	if (!s)
		return (NULL);
	i = -1;
	str = (char **)malloc(sizeof(char *) * 3);
	if (!str)
		return (NULL);
	while(s && *s == ' ')
		s++;
	len = first_word(s, c);
	rest = ft_strlen(s) - (len);
	if (rest < 0)
		rest = ft_strlen(s);
	str[0] = (char *)malloc(sizeof(char) * len + 1);
	str[1] = (char *)malloc(sizeof(char) * (rest + 1));
	str[2] = 0;
	ft_strlcpy(str[0], s, len + 1);
	ft_strlcpy(str[1], &s[len + 1], rest);
	return (str);
}