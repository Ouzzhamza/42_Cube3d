/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:51:26 by houazzan          #+#    #+#             */
/*   Updated: 2022/08/05 11:43:52 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/cube3d.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit (EXIT_FAILURE); //& this one should be executed after freeing every thing
}
