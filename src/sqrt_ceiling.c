#include "../include/fillit.h"

int		sqrt_ceiling(int n)
{
	int		size;

	size = 2;
	while(size * size < n)
		size++;
	return (size);
}
