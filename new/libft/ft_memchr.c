/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:57:58 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 22:58:36 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char*)s;
	ch = (unsigned char)c;
	while (n)
	{
		if (*str == ch)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
