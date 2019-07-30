#include "libft.h"

int ft_strlchr(const char *str, int symbol, int num_s)
{
	int len;

	len = 0;
	if (num_s <= 0)
		return (0);
	while (num_s > 0)
	{
		while (str[len] && str[len] != symbol)
			len++;
		num_s--;
		len++;
	}
	len--;
	if (str[len] != symbol)
		return (0);
	return (len);
}
