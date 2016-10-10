#include "fillit.h"

t_list	*ft_lstrev(t_list **list)
{
	t_list	*next;
	t_list	*current;
	t_list	*prev;

	prev = NULL;
	current = *list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list = prev;
	return(*list);
}
