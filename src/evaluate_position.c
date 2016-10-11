#include "../include/fillit.h"

int		evaluate_position(t_tet *tetri, t_map *map, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < tetri->height)
	{
		i = 0;
		while(i < tetri->width)
		{
			if (tetri->tab[j][i] == '#' && map->grid[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	if (redundant_move(tetri, x, y) == 1)
		return (0);
	tetri->y = y;
	tetri->x = x;
	update_glst(tetri->val, x, y);
	alter_map(tetri, map, new_vector(x, y), tetri->val);
	return (1);
}
