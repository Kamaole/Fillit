#include "../include/fillit.h"

int			redundant_move(t_tet *tetri, int x, int y)
{
	t_list	*link;
	t_tet	*temp;
	int 	ret;
	int		match;

	ret = 1;
	match = 0;
	//link = ft_lstrev(list);
	//print_list(g_list);
	link = g_list;
	while (link)
	{
		temp = (t_tet *)(link->content);
		// if (found)
		if (temp->val < tetri->val)
		{
			// ft_putendl(&temp->val);
			// ft_putendl(&tetri->val);
			if ( temp->height == tetri->height && temp->width == tetri->width
				&& (ft_tabcmp(tetri->tab, temp->tab, temp->height)))
			{
				match = 1;
				if (temp->y < y || (temp->y == y && temp->x < x))
				{
					// ft_putnbr(temp->y);
					// ft_putchar('\n');
					// ft_putnbr(y);
					// ft_putchar('\n');
					// ft_putnbr(temp->x);
					// ft_putchar('\n');
					// ft_putnbr(x);
					// ft_putchar('\n');
					// ft_putendl("Match found");
					ret = 0;
				}
				break ;
			}
		}
		// }
		// if (temp->val == tetri->val)
		// 	found = 1;
		link = link->next;
	}
	if (match)
		return (ret);
	return (0);
}
