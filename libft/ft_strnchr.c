#include "libft.h"

int		ft_strnchr(const char *str, int symbol)
{
	size_t		i;
	int 		num;
	size_t		len;

	i = 0;
	num = 0;
	len = ft_strlen(str);
	if (!(ft_strchr(str, symbol)))
		return (0);
	while (i < len)
	{
		if (str[i] == symbol)
			num++;
		i++;
	}
	return (num);
}