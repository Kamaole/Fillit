#include "../include/fillit.h"

t_list	*read_source(int fd)
{
	char	*buf;		//Write into buf from file
	int		size_read;  //Number of bytes read in 
	t_tet	*tetri;
	t_list	*list;
	char	c;
//	int errnum;

	buf = ft_strnew(21);//21 because 4 * 4 grid w/ newline at each line and newline after
	list = NULL;
	c = 'A';
	while ((size_read = read(fd, buf, 21)) >= 20)//The last tetrimino will be 20 bytes cuz no newline after
	{
		if (!(is_valid_input(buf, size_read)) || (tetri = get_tetri(buf, c)) == NULL)
		{
			//ft_memdel((void **)&buf);
			//free list
			//ft_putnbr(errnum);
			ft_putendl("\nFailed if");
			return (NULL);
		}
		c++;
		if (c > 'Z')
			return (NULL);
		ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tet)));
		ft_lstadd(&g_list, ft_lstnew(tetri, sizeof(t_tet)));	
		//free tetris ??
	}
	//ft_memdel((void **)&buf);
	if (size_read != 0)
	{
		//free list
		return (NULL);
	}
	ft_lstrev(&list);
	return (list);

}
