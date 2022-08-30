/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:58:59 by mmoumni           #+#    #+#             */
/*   Updated: 2022/08/30 16:58:22 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structs.h"
#include "../../includes/cub3d.h"

char	*read_line(char *static_buff, int fd)
{
	char	*buffer;
	int		n;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = 1;
	while (n > 0 && ft_strchr(static_buff, '\n') == NULL)
	{	
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n] = '\0';
		if (n == 0)
			break ;
		static_buff = ft_strjoin(static_buff, buffer);
	}
	free(buffer);
	return (static_buff);
}

char	*backup_func(char *backup)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (backup[len] != '\n' && backup[len] != '\0')
		len++;
	if (backup[len] == '\0')
	{
		free(backup);
		return (NULL);
	}
	dest = ft_strdup(backup + len + 1);
	free(backup);
	if (dest[0] == '\0')
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*line;
	int				i;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_line(backup, fd);
	if (backup == NULL)
		return (NULL);
	i = -1;
	len = 0;
	while (backup[len] != '\n' && backup[len] != '\0')
		len++;
	if (backup[len] == '\n')
		len = len + 1;
	line = malloc(sizeof(char) *(len + 1));
	if (!line)
		return (NULL);
	while (++i < len)
		line[i] = backup[i];
	line[i] = '\0';
	backup = backup_func(backup);
	return (line);
}
