#include "fillit.h"

t_tet	*new_tetri(char **pos, int w, int h, char c)
{
	t_tet	*tetri;


	tetri = ft_memalloc(sizeof(t_tet));
	tetri->tab = pos;
	tetri->width = w;
	tetri->height = h;
	tetri->val = c;
	tetri->x = 0;
	tetri->y = 0;
	return (tetri);
}

int		block_continuity(char *str)
{
	int i;
	int cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			//check left of block
			if (i > 0 && str[i - 1] == '#')
				cont++;
			//check right of block
			if (i < 20 && str[i + 1] == '#')
				cont++;
			//check above block(visually)...empirically below
			if (i > 4 && str[i - 5] == '#')
				cont++;
			//check below block ''  ''  ''
			if (i < 15 && str[i + 5] == '#')
				cont++;
		}
		i++;
	}
	//All tetri have a conection count of 6, except for the square which has 8
	if (cont == 6 || cont == 8)
		return (1);
	return (0);
}

void	get_limits(char *str, t_vec *min, t_vec *max)
{
	int i;

	i = 0;
	while (str[i])
	{
		//for each block
		if (str[i] == '#')
		{
			//change the char from # to alpha value
			//str[i] = c;
			//if index in line is less than min x value, change it
			if (i % 5 < min->x)
				min->x = i % 5;
			//if index in line is greater that max x, change it
			if (i % 5 > max->x)
				max->x = i % 5;
			//if line number is less than min y, change it
			if (i / 5 < min->y)
				min->y = i / 5;
			//if line number is greater than max y, change it
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

int		is_valid_input(char *str, int size_read)
{
	int i;
	int	blocks;

	i = 0;
	blocks = 0;
	//if not last tetri then it needs to be followed by a new line
	if (size_read == 21 && str[20] != '\n')
		return (0);
	while (i < 20)
	{
		//if index is part of the grid. ex i= 0 thru 3 are part of tetri grid
		if (i % 5 < 4)
		{
			//invalid char in grid
			if (str[i] != '.' && str[i] != '#')
				return (0);
			//too many blocks in tetri
			if (str[i] == '#' && ++blocks > 4)
				return (0);
		}
		else if (str[i] != '\n')//when index mod 5 == 4 it should be  newline char
			return(0);
		i++;
	}
	if (!block_continuity(str))
		return (0);
	return (1);
}

t_tet	*get_tetri(char *str, char c)
{
	t_vec	*min;
	t_vec	*max;
	t_tet	*tetri;
	char	**pos;
	int		i;

	//create min vector - init to largest extreme
	min = new_vector(3, 3);
	//create max vector - init to smallest extreme
	max = new_vector(0, 0);

	get_limits(str, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));//amount of strings = tetri height
	i = 0;
	while (i < max->y - min->y + 1)
	{
		//size is = to tetri width 
		pos[i] = ft_strnew(max->x - min->x + 1);
		//get each line   ptr + min x value + ( index + min height ) * 5(number of chars per line) 
		ft_strncpy(pos[i], (str + min->x + (i + min->y) * 5), (max->x - min->x + 1));
		i++;
	}
	// i = 0;
	// while (i < max->y - min->y + 1)
	// {
	// 	ft_putendl(pos[i]);
	// 	i++;
	// }
	tetri = new_tetri(pos, max->x - min->x + 1, max->y - min->y + 1, c);
	//free min and max
	return (tetri);
}
