/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:51:02 by yjohns            #+#    #+#             */
/*   Updated: 2019/09/12 15:43:57 by ialleen          ###   ########.fr       */
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
	while (i < size)
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

	unsigned	a;
	unsigned i;
	unsigned b;

	i = 0;
	b = 0;
    a = fig->fig;
	a = a << 16;
	i = 0;
	while (i < MAX_ROW) {
        if (i < 4)
        {
			fig->matr[i] = a & 0xF0000000;
            a = a << 4;
        }
	    i++;
    }
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
	if (y > tet->max_w_h - 1)
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
	unsigned y1;
	unsigned y2;
	int a;

	a = 0;
	y1 = tet1->y;
	y2 = tet2->y;
	while (y1 < tet1->y + tet1->height)
	{
		a = ((tet1->matr[y1++] & tet2->matr[y2++]) == 0) ? 1 : 0;
		if (a)
			return (0);

	}
	return (1);
}

void map(t_tet *head)
{
    unsigned a;
    t_tet *tet;

    tet = head;
    while (head)
    {
        a = head->fig;
        start_data(head);
        bit_to_matr(head);

        a = 1;
        while (a)
		{
			print_square_matr(head, head->max_w_h);
        	while (sdvig_right(head))
				print_square_matr(head, head->max_w_h);
			sdvig_left(head);
        	a = sdvig_down(head);
		}
        //print_square_matr(head, head->max_w_h);
        head = head->next;
    }
}

