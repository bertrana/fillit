/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:10:52 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 14:00:55 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*cdst;
	char	*csrc;
	size_t	n;
	size_t	dlen;

	n = size;
	cdst = dst;
	csrc = (char *)src;
	while (n-- > 0 && *cdst)
		cdst++;
	dlen = cdst - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(csrc));
	while (*csrc)
	{
		if (n != 1)
		{
			*cdst++ = *csrc;
			n--;
		}
		csrc++;
	}
	*cdst = '\0';
	return (dlen + (csrc - src));
}
