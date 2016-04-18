/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:20:44 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/08 22:47:40 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	get_line(int const fd, char *buffer, char *save)
{
	int				ret;
	char			*c;
	char			*tmp;

	while ((c = ft_strchr(buffer, '\n')) == NULL &&
			(ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	ft_strdel(&buffer);
	if (ret == -1)
		return (-1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char		*save;
	char			*buffer;
	int				ret;
	char			*str;
	char			*tmp;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buffer == NULL || BUFF_SIZE < 1)
		return (-1);
	if (save == NULL)
		save = ft_strnew(1);
	if ((ret = get_line(fd, buffer, save)) == -1)
		return (-1);
	if ((str = ft_strchr(save, '\n')) != NULL)
	{
		*line = ft_strsub(save, 0, str - save);
		tmp = save;
		save = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(save);
	save = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
