/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:56:46 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/04 15:14:27 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	c;
	char	sc;
	size_t	len_n;

	if ((c = *needle++))
	{
		len_n = ft_strlen(needle);
		while (1)
		{
			while (1)
			{
				if (len-- < 1 || !(sc = *haystack++))
					return (NULL);
				if (sc == c)
					break ;
			}
			if (len_n > len)
				return (NULL);
			if (!(ft_strncmp(haystack, needle, len_n)))
				break ;
		}
		haystack--;
	}
	return ((char *)haystack);
}
