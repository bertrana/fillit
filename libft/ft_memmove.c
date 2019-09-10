/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:03:12 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/04 12:21:16 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (cdst <= csrc || cdst >= (csrc + len))
		while (len--)
			*(cdst++) = *(csrc++);
	else
	{
		cdst += len;
		csrc += len;
		while (len--)
			*(--cdst) = *(--csrc);
	}
	return (dst);
}
