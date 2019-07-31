#include "main.h"

t_tetr	*ft_lstaddtetr(t_tetr *list, const char *str)
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
