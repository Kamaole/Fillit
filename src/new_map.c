#include "../include/fillit.h"

t_map	*new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->grid = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->grid[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
