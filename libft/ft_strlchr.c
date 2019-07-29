#include "libft.h"

int ft_strlchr(char *str, int symbol)
{
	int len;

	len = 0;
	while (str && *str != symbol)
	{
		str++;
		len++;
	}
	if (*str != symbol)
		return (0);
	return (len);
}
