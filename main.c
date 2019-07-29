#include "main.h"

t_tetr	*add_new_list(t_tetr *list, const char *str)
{
	t_tetr	*new;
	t_tetr	*start;

	start = list;
	if (!(new = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	new->start = ft_strchr(str, '#');
	new->sec = ft_strlchr(new->start, '#');
	new->third = ft_strlchr(new->start + new->sec + 1, '#');
	new->four = ft_strlchr(new->start + new->sec + new->third + 1, '#');
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

	if ((read(fd, str, 30)) != 21)
		return (-1);
	str[21] = '\0';
	if (ft_strnchr(str, '#') != 4 || ft_strnchr(str, '.') != 12 || ft_strnchr(str, '\n') != 5)
		return (-1); //not valid file
	if (!(add_new_list(list, str)))
		return (-1);
	return (0);
}
//|| !(list = (t_list *)malloc(sizeof(t_list)))

int		main(int argv, char **argc)
{
	int				fd;
	static t_tetr	*list = NULL;

//	printf("argv = %d\nargc[0] = %s\nargc[1] = %s\n", argv, argc[i], argc[i + 1]);
	if (argv == 1)
		return (-1); //EXIT
	while (argv > 1)
	{
		argc++;
		if ((fd = open(*argc, O_RDONLY)) < 3 || tetr_read(fd, list) == -1)
			return (-1); //EXIT
		argv--;
	}
	return (0);
}