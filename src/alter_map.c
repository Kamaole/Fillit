#include "../include/fillit.h"

void	alter_map(t_tet *tetri, t_map *map, t_vec *pos, char c)
{
	int	i;
	int	j;
	// int z;

	// z = 0;
	// while (tetri->tab[0][z] != tetri->val)
	// 	z++;
	// if (pos->x >= z)
	// 	pos->x -= z;

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
	// if (++g_cnt == 15)
	// {
	// 	print_map(map);
	// 	ft_putchar('\n');
	// 	usleep(10000);
	// 	g_cnt = 0;
	// }
}
