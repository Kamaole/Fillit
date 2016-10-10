#include "fillit.h"

int		ft_lstcount(t_list *list)
{
	if(list->next == NULL)
		return (1);
	return (1 + ft_lstcount(list->next));
}
