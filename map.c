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

void	print_square_matr(int **matr, int size)
{
	int i;
	int j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
		{
			printf("%d", matr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


int		**bit_to_matr(int square, int fig)
{
	//может надо сделать динамическое выделение памяти? Хотя не особо понятно зачем
	int matr[square][square];
	int	i;
	int j;

	i = square - 1;
	//убираем лишние битовые строчки, одна у фигуры шириной 3 и две у квадрата
	if (square == 3)
		fig = fig >> 4;
	else if (square == 2)
		fig = fig >> 8;
	while (i >= 0)
	{
		//чтобы не записывать в матрицу лишние символы, считываем только наш квадрат
		//т.е "обрезаем" лишние элементы строки (2, 1, или 0)
		fig = fig >> (4 - square);
		j = square - 1;
		while (j >= 0)
		{
			//вот здесь, скорее всего, основной косяк: в матрицу не записываются числа.
			//вообще никакие. Хотя, возможно, это потому что под матрицу не выделена память? хз
			matr[i][j] = ((fig >> 1 & 1) ? 1 : 0);
			fig = fig >> 1;
			j--;
		}
		i--;
	}
	print_square_matr(matr, square - 1);
	return (matr);
}

void    map(t_tet *l_tetr)
{
	t_tet	*begin;

	begin = l_tetr;
    while(l_tetr->next)
    {
    	l_tetr->matr = bit_to_matr(l_tetr->min_square, l_tetr->fig);
        l_tetr = l_tetr->next;
    }
    l_tetr = begin;
}