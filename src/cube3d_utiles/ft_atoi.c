/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:08:36 by houazzan          #+#    #+#             */
/*   Updated: 2022/09/01 19:50:45 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	res;
// 	int	signe;

// 	i = 0;
// 	res = 0;
// 	signe = 1;
// 	while (str[i] == ' ' || str[i] == '\f' || \
// 	str[i] == '\n' || str[i] == '\r' || \
// 	str[i] == '\t' || str[i] == '\v')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			signe *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (res * signe);
// }

int	ft_isspace(char c)
{
	if (c == '\v' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	rest(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || \
	str[i] == '\n' || str[i] == '\r' || \
	str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int				i;
	long long int	res;
	int				signe;

	res = 0;
	signe = 1;
	i = rest(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	while (str && ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return(-2);
	return (res * signe);
}