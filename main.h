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
	char 			*start;
	int 			sec;
	int 			third;
	int 			four;
	struct s_tetr	*next;
}					t_tetr;

int 				tetr_read(int fd, t_tetr *list);

#endif
