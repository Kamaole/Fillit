/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:57:16 by ahunt             #+#    #+#             */
/*   Updated: 2016/10/07 17:02:29 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	t_map	*map;

	//Only accept one arguement
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetrimino_source_file");
		return (0);
	}//open the file passed in
	if ((fd = open(argv[1], O_RDONLY, 0600)) == -1)
	{
		ft_putendl("File wouldn't open");
		return (0);
	}
	ft_putendl("going to read source");
	if (!(list = read_source(fd)))
	{
		ft_putendl("List is NULL");
		return (0);
	}
	map = init_solver(list);
	print_map(map);
	return (0);
}
