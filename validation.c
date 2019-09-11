/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:50:13 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/09 21:49:41 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_line(const int fd, char *line)
{
	int		n_line;
	int		count_x;
	int		count_o;
	int		len;

	n_line = 0;
	count_x = 0;
	count_o = 0;
	while (n_line++ < 4)
		if (get_next_line(fd, &line) && (len = ft_strlen(line)))
		{
			while (--len > -1)
				if (line[len] == '#')
					count_x++;
				else if (line[len] == '.')
					count_o++;
			if (ft_strlen(line) != 4 || count_x > 4)
			{
				free(line);
				return (-1);
			}
			free(line);
		}
	return ((count_x == 4 && (count_o + count_x) == 16) ? 1 : -1);
}

int			check_tetramino(int a)
{
	int		i;
	int		j;

	while (!(a >> 3 & 1 || (a >> 7 & 1) || (a >> 11 & 1) || (a >> 15 & 1)))
		a = a << 1;
	while (!(a >> 15 & 1 || (a >> 14 & 1) || (a >> 13 & 1) || (a >> 12 & 1)))
		a = a << 4;
	return ((F_ZR == a || F_ZR_ROT == a || F_ZL == a || F_ZL_ROT == a ||
		F_GL_U == a || F_GL_L == a || F_GL_D == a || F_GL_R == a ||
		F_GR_U == a || F_GR_L == a || F_GR_D == a || F_GR_R == a ||
		F_T_L == a || F_T_U == a || F_T_R == a || F_T_D == a ||
		F_BLOCK == a || F_LINE_U == a || F_LINE_L == a) ? a : 0);
}

t_tet		*validation(int fd, char *file)
{
	t_tet	*head;
	char	*mas;
	int		i;
	int		a;
	char	id;

	validation_1(fd) ? (fd = open(file, O_RDONLY)) : ft_exit();
	mas = ft_memalloc(21);
	id = 'A';
	head = NULL;
	while ((read(fd, mas, 21)) > 0 && (i = -1))
	{
		a = 0;
		while (++i < 21)
		{
			if (mas[i] == '#')
				a = a | 1;
			a = (mas[i] == '#' || mas[i] == '.') ? a << 1 : a;
		}
		if (!(a = check_tetramino(a >> 1)))
			ft_exit();

		!head ? head = tetnew(id++, a) : tetadd(&head, tetnew(id++, a));
	}
	free(mas);
	return (head);
}

int			validation_1(const int fd)
{
	char	*line;
	int		count_lines;
	int		r;

	count_lines = 0;
	line = NULL;
	while ((r = check_line(fd, line)) > 0)
	{
		count_lines++;
		if (!get_next_line(fd, &line))
			break ;
		if (ft_strlen(line))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
	}
	close(fd);
	if (r == -1 || !(count_lines > 0 && count_lines < 27))
		return (0);
	return (count_lines);
}