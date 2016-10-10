#include "fillit.h"

void	free_tetri(t_tet *tetri)
{
	int i;

	i = 0;
	while (i < tetri->height)
	{
		ft_memdel((void **)&(tetri->tab[i]));
		i++;
	}
	ft_memdel((void **)&(tetri->tab));
	ft_memdel((void **)&tetri);
}

t_list	*free_list(t_list *list)
{
	t_tet	*tetri;
	t_list	*next;

	while (list)
	{
		tetri = (t_tet *)(list->content);
		free_tetri(tetri);
		next = list->next;
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->grid[i]));
		i++;
	}
	ft_memdel((void **)&(map->grid));
	ft_memdel((void **)&map);
}
