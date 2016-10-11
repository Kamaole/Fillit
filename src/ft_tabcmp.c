#include "../include/fillit.h"

int		ft_tabcmp(char **s1, char **s2, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		if (ft_strequ(s1[i], s2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
