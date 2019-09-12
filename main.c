/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:02:17 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/12 10:59:25 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_exit(void)
{
	ft_putstr_fd("error\n", 2);
	exit(EXIT_FAILURE);
}

int			main(int argc, char *argv[])
{
	int		fd;
	t_tet	*lines;

	if (argc != 2)
		ft_exit();
	else if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_exit();
		else if (fd > 0)
		{

			if ((lines = validation(fd, argv[1])))
			{
				map(lines);
				while (lines)
				{
					printf("%c\t%d\n", lines->id, lines->fig);
					lines = lines->next;
				}
			}
			else
				ft_exit();
		}
		close(fd);
	}
	return (0);
}
