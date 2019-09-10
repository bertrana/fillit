/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:50:14 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 17:34:38 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			len;
	char			*map;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (len + 1 < len)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	map = str;
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (map);
}
