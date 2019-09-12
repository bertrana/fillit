#include "fillit.h"

int sdvig_left(t_tet *tet)
{
	unsigned j;
	unsigned y;

	j = tet->y;

	y = j + tet->height;
	if (tet->x == 0)
		return (0);
	while (j <= y)
	{
		tet->matr[j] = (tet->matr[j]) << tet->x;
		j++;
	}
	(tet->x) = 0;
	return (1);
}

int sdvig_up(t_tet *tet)
{
	int j;
	int y;

	j = 0;
	y = tet->y;
	if (tet->y == 0)
		return (0);
	while (j <= tet->height)
	{
		tet->matr[j++] = tet->matr[y];
		tet->matr[y++] = 0;
	}
	(tet->y) = 0;
	return (1);
}

int	zero(t_tet *tet)
{
	int a;
	int b;

	a = sdvig_left(tet);
	b = sdvig_up(tet);
	return (a + b);
}

int	end_pos(t_tet *tet)
{
	return (tet->y == 0 && tet->x == 0);
}