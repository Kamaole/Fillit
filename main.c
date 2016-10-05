/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:57:16 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/05 15:57:25 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	get_limits(char *str, t_vec min, t_vec max)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

t_tet	*get_tetri(char *str, char c)
{
	t_vec	*min;
	t_vec	*max;
	t_tet	*tetri;
	char	**pos;
	int		i;

	min = new_vector(3, 3);
	max = new_vector(0, 0);

	get_limits(str, min, max);
	pos = ft_memalloc(sizeof(char *) * max->y - min->y + 1);
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], (str + min->x + (i + min->y) * 5), (max->x - min->x + 1));
		i++;
	}
	tetri = new_tetri(pos, max->x - min->x + 1, max->y - min->y + 1, c);
	//free min and max
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
			if (i > 0 && str[i - 1] == '#')
				cont++;
			if (i < 20 && str[i + 1] == '#')
				cont++;
			if (i > 4 && str[i - 5] == '#')
				cont++;
			if (i < 15 && str[i + 5] == '#')
				cont++;
		}
		i++;
	}
	if (cont == 6 || cont == 8)
		return (1);
	return (0);
}

int		is_valid_input(char *str, int size_read)
{
	int i;
	int	blocks;

	i = 0;
	blocks = 0;
	if (size_read == 21 && str[20] != '\n')
		return (0);
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '.' || str[i] != '#')
				return (0);
			if (str[i] == "#" && ++blocks > 4)
				return (0);
		}
		else if (str[i] != '\n')
			return(0);
		i++;
	}
	if (!block_continuity(str))
		return (0);
	return (1);
}

t_list	*read_source(int fd)
{
	char	buf[21];
	int		size_read;
	t_tet	*tetri;
	t_list	*list;
	char	c;

	while ((size_read = read(fd, buf, 21)) >= 20)
	{
		if (!is_valid_input(buf, size_read) || (tetri = get_tetri(buf, c) == NULL))
		{
			ft_memdel((void **)&buf);
			//free list
			return (NULL);
		}
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tet)));
		//free tetris ??
	}
	ft_memdel((void **)&buf);
	if (size_read != 0)
	{
		//free list
		return (NULL);
	}
	return (list);

}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetrimino_source_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY, 0600)) == -1)
	{
		ft_putendl("File wouldn't open");
		return (0);
	}
	list = read_source(fd);
}