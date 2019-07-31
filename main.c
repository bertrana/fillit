#include "main.h"

int		ft_lsttlen(t_tetr *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	algorithm(t_tetr *list)
{
	int		len;

	len = ft_lsttlen(list);
	printf("len of list = %d", len);
	return ;
}

int		main(int argv, char **argc)
{
	int		fd;
	t_tetr	*list;

	list = NULL;
	if (argv != 2)
		return (-1); //EXIT
	if ((fd = open(argc[1], O_RDONLY)) < 3 || !(list = ft_fileread(fd, list)))
		return (-1); //EXIT
	algorithm(list);
	//write to file
	//delete list & matr
	return (0);
}