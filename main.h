//
// Created by Valiko on 29.07.2019.
// The allowed functions are : exit, open, close, write, read, malloc and free

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct 		s_tetr
{
	int 			sec;
	int 			third;
	int 			four;
	struct s_tetr	*next;
}					t_tetr;

t_tetr				*ft_fileread(int fd, t_tetr *list);
t_tetr				*ft_lstaddtetr(t_tetr *list, const char *str);

#endif
