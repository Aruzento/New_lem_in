/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:54:23 by erandal           #+#    #+#             */
/*   Updated: 2020/08/12 18:52:38 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_put(char *c, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (c[0] != '\0')
	{
		while (c[i] != '\n' && c[i] != '\0')
			i++;
		*line = ft_strsub(c, 0, i);
		tmp = ft_strsub(c, i + 1, ft_strlen(c) - i);
		ft_strdel(&c);
		if (!tmp)
			c = ft_strnew(0);
		else
			c = tmp;
	}
	return (c);
}

int		clear(int ret, char *c)
{
	if ((ret == 0) && (c[0] == '\0'))
		ft_strdel(&c);
	else if (c[0] == '\0')
		ft_strdel(&c);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*c[OPEN_MAX];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if ((fd < 0) || (!line) || (fd > OPEN_MAX))
		return (-1);
	if (!c[fd])
		c[fd] = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(c[fd], buff)) || !c[fd])
			return (-1);
		ft_strdel(&(c[fd]));
		c[fd] = tmp;
		if (ft_strchr(c[fd], '\n'))
			break ;
	}
	if ((ret == 0) && (c[fd][0] != '\0'))
		ret++;
	c[fd] = save_put(c[fd], &(*line));
	if ((ret == 0) && c[fd][0] == '\0')
		return (clear(ret, c[fd]));
	return ((ret >= 0) ? 1 : ret);
}
