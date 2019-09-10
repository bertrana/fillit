/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:08:14 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/08 00:47:14 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*create_line(char const *s1, char const *s2)
{
	char		*result;

	if ((result = ft_strjoin(s1, s2)))
		free((char *)s1);
	return (result);
}

static void		change_pos(char *str, char **rest)
{
	char		*tmp;

	if (str && *str)
	{
		tmp = *rest;
		*rest = ft_strdup(str);
		free(tmp);
	}
}

static int		get_start(char **line, char **fd_list, char **pos)
{
	if (*fd_list && **fd_list)
	{
		if ((pos[0] = ft_strchr(*fd_list, '\n')))
		{
			*pos[0] = '\0';
			*line = create_line(*line, *fd_list);
			change_pos(pos[0] + 1, fd_list);
			if (ft_strequ(*fd_list, *line))
				ft_strclr(*fd_list);
			return (1);
		}
		else
			*line = create_line(*line, *fd_list);
		if (!ft_strchr(*fd_list, '\n'))
			ft_strclr(*fd_list);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			r;
	char		*pos;
	char		buf[BUFF_SIZE + 1];
	static char	*fd_list[OPEN_MAX];

	if (fd < 0 || (fd > OPEN_MAX) || !line || !(*line = ft_strnew(0)))
		return (-1);
	if (get_start(line, &fd_list[fd], &pos))
		return (1);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if ((pos = ft_strchr(buf, '\n')))
		{
			pos[0] = '\0';
			change_pos(pos + 1, &fd_list[fd]);
			*line = create_line(*line, buf);
			return (1);
		}
		*line = create_line(*line, buf);
	}
	if (**line && !r)
		return (1);
	return (r);
}
