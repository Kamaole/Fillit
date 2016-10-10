#include "fillit.h"

void	update_glst(char c, int x, int y)
{
	t_list	*link;
	t_tet	*tetri;

	link = g_list;
	while (link)
	{
		tetri = (t_tet *)(link->content);
		if (tetri->val == c)
		{
			tetri->y = y;
			tetri->x = x;
			break ;
		}
		link = link->next;
	}
}
