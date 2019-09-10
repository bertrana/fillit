/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:39:31 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 17:34:04 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;
	char	*map;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (len + 1 < len)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	map = str;
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (map);
}
