#include "main.h"

t_tetr	*ft_fileread(int fd, t_tetr *list)
{
	char	str[22];
	char 	*tmp;
	int 	num_read = 1;

	while (num_read != 0)
	{
		if ((num_read = read(fd, str, 21)) < 20 && num_read != 0)
			return (NULL);
		if (num_read == 0 && list)
			break ;
		str[num_read] = '\0';
		if (ft_strnchr(str, '#') != 4 || ft_strnchr(str, '.') != 12 ||
			(num_read == 21 && ft_strnchr(str, '\n') != 5) ||
			(num_read == 20 && ft_strnchr(str, '\n') != 4))
			return (NULL);
		if (!(list = ft_lstaddtetr(list, str)))
			return (NULL);
	}
	return (list);
}
