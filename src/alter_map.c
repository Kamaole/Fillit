#include "../include/fillit.h"

void	alter_map(t_tet *tetri, t_map *map, t_vec *pos, char c)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < tetri->height)
	{
		i = 0;
		while (i < tetri->width)
		{
			if (tetri->tab[j][i] == '#')
			{
				map->grid[pos->y + j][pos->x + i] = c;
			}
			i++;
		}
		j++;
	}
	ft_memdel((void **)&pos);
}
