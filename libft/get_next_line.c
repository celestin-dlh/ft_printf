/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:25:42 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/19 12:40:09 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_error(int fd, char **line)
{
	if (fd < 0 || line == NULL)
		return (-1);
	return (0);
}

static int			attribute_line(char **line, char **s, int fd)
{
	int		len;
	char	*temp;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		temp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = temp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*s[256];
	char			*temp;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (check_error(fd, line) == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		temp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && ((s[fd] == NULL || s[fd][0] == '\0')))
		return (0);
	return (attribute_line(line, s, fd));
}
