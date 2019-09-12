/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:51:02 by yjohns            #+#    #+#             */
/*   Updated: 2019/09/12 14:40:38 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_square_matr(t_tet *fig, int size)
{
	unsigned i;
	unsigned j;
	unsigned a;

	i = 0;
	while (i <= size)
	{
	    j = 0;
        a = fig->matr[i];
	    while (j < size)
	    {
	        if (a & 0x80000000)
                ft_putchar('#');
	        else
                ft_putchar('.');
	        a = a << 1;
            j++;
        }
        ft_putchar('\n');
		i++;
	}
    ft_putchar('\n');
}


void	bit_to_matr(t_tet *fig)
{
	unsigned *matr;
	unsigned	a;
	unsigned i;
	unsigned b;

	i = 0;
	b = 0;
    a = fig->fig;
	a = a << 16;
	i = 0;
    matr = (unsigned *)malloc(sizeof(unsigned) * 32);
	while (i < 32) {
        if (i < 4)
        {
            matr[i] = a & 0xF0000000;
            a = a << 4;
        }
	    i++;
    }
	fig->matr = matr;
}

void    start_data(t_tet *head)
{
    int a;

    head->x = 0;
    head->y = 0;
    a = head->fig;
    if (a == F_ZR_ROT || a == F_ZL_ROT || a == F_GL_U || a == F_GL_D ||
        a == F_GR_U || a == F_GR_D || a == F_T_U || a == F_T_D)
    {
        head->width = 3;
        head->height = 2;
    }
    else if (a == F_BLOCK && (head->width = 2))
        head->height = 2;
    else if (a == F_LINE_L && (head->width = 1))
        head->height = 4;
    else if (a == F_LINE_U && (head->width = 4))
        head->height = 1;
    else if ((head->width = 2))
        head->height = 3;
}
int sdvig_right(t_tet *tet)
{
	unsigned j;
	unsigned y;

	j = tet->y;

	y = j + tet->height;
	if (tet->x + tet->width >= tet->max_w_h)
		return (0);
	while (j <= y)
	{
		tet->matr[j] = (tet->matr[j]) >> 1;
		j++;
	}
	(tet->x)++;
	return (1);
}

int sdvig_down(t_tet *tet)
{
	int j;
	int y;

	j = tet->y;
	y = tet->y + tet->height;
	if (y > tet->max_w_h)
		return (0);
	while (j <= y)
	{
		tet->matr[y] = tet->matr[y - 1];
		y--;
	}

	tet->matr[tet->y] = 0;
	(tet->y)++;
	return (1);
}

int 	compare_tet(t_tet *tet1, t_tet *tet2)
{
	int y1;
	int y2;
	int j_min;
	int j_max;
	int a;

	a = 0;
	y1 = tet1->y;
	y2 = tet2->y;
	j_min = (y1 > y2) ? y2 : y1;
	j_max = (y1 > y2) ? y1 : y2;
	while (j_min <= j_max)
	{
		a = ((tet1->fig & tet2->fig) == 0) ? 1 : 0;
		if (a)
			return (0);
		j_min++;
	}
	return (1);
}

void map(t_tet *head)
{
    unsigned a;

    while (head)
    {
        a = head->fig;
        start_data(head);
        bit_to_matr(head);
        print_square_matr(head, head->max_w_h);
        head = head->next;
    }
}

