#include "main.h"

t_tetr	*add_new_list(t_tetr *list, const char *str)
{
	t_tetr	*new;
	t_tetr	*start;
	int 	i;

	start = list;
	if (!(new = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	i = ft_strlchr(str, '#', 1);
	new->sec = ft_strlchr(str, '#', 2) - i;
	new->third = ft_strlchr(str, '#', 3) - i - new->sec;
	new->four = ft_strlchr(str, '#', 4) - i - new->sec - new->third;
	new->next = NULL;
	printf("new->sec = %d\n", new->sec);
	printf("new->third = %d\n", new->third);
	printf("new->four = %d\n", new->four);
	if (list == NULL)
		start = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	return (start);
}

int 	tetr_read(int fd, t_tetr *list)
{
	char	str[22];
	char 	*tmp;
	int 	num_read = 1;

	while (num_read != 0)
	{
		if ((num_read = read(fd, str, 26)) < 20 && num_read != 0)
			return (-1);
		if (num_read == 0 && list)
			break ;
		str[num_read] = '\0';
		if (ft_strnchr(str, '#') != 4 || ft_strnchr(str, '.') != 12 ||
				(num_read == 21 && ft_strnchr(str, '\n') != 5) ||
				(num_read == 20 && ft_strnchr(str, '\n') != 4))
			return (-1); //not valid file
		if (!(list = add_new_list(list, str)))
			return (-1);
	}
		return (0);
}
//|| !(list = (t_list *)malloc(sizeof(t_list)))

int		main(int argv, char **argc)
{
	int		fd;
	t_tetr	*list = NULL;

//	printf("argv = %d\nargc[0] = %s\nargc[1] = %s\n", argv, argc[i], argc[i + 1]);
	if (argv != 2)
		return (-1); //EXIT
	if (argv == 2)
		if ((fd = open(argc[1], O_RDONLY)) < 3 || tetr_read(fd, list) == -1)
			return (-1); //EXIT
	return (0);
}