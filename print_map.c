#include "fillit.h"

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->grid[i++]);
}
