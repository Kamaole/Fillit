#include "../include/fillit.h"

t_vec	*new_vector(int x, int y)
{
	t_vec *vector;

	vector = ft_memalloc(sizeof(t_vec));
	vector->x = x;
	vector->y = y;
	return (vector);
}
