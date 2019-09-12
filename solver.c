#include "fillit.h"

void	matrix_zero(t_tet *tet)
{
	int	i;

	i = 0;
	while (i < MAX_ROW)
		tet->matr[i++] = 0;
}

t_tet	*solver(t_tet *head)
{
	t_tet *matrix;
	matrix = tetnew(0,0,head->max_w_h);
	matrix_zero(matrix);
	matrix->x = 0;
	matrix->y = 0;
	matrix->width = head->width;
	matrix->height = head->height;

}

