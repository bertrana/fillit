/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:51:02 by yjohns            #+#    #+#             */
/*   Updated: 2019/09/11 10:52:44 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_square_matr(t_tet *fig, int size)
{
	int i;
	int j;
    int a;

	i = 0;
	while (i <= size)
	{
	    j = 0;
        a = fig->matr[i];
	    while (j < size)
	    {
	        if (a & 0x8000000000)
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
	int *matr;
	int	a;
	int i;
	int b;

	i = 0;
	b = 0;
    a = fig->fig;
	a = a << 16;
	i = 0;
    matr = (int *)malloc(sizeof(int) * 32);
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
    if (a == F_ZR || a == F_ZL || a == F_GL_U || a == F_GL_D ||
        a == F_GR_U || a == F_GR_D || a == F_T_U || a == F_T_D)
    {
        head->max_x = 3;
        head->max_y = 2;
    }
    else if (a == F_BLOCK && (head->max_x = 2))
        head->max_y = 2;
    else if (a == F_LINE_L && (head->max_x = 1))
        head->max_y = 4;
    else if (a == F_LINE_U && (head->max_x = 4))
        head->max_y = 1;
    else if ((head->max_x = 2))
        head->max_y = 3;
}

void map(t_tet *head)
{
    int a;

    while (head)
    {
        a = head->fig;
        start_data(head);
        bit_to_matr(head);
        print_square_matr(head, 5);
        head = head->next;
    }
}

