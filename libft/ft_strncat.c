/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:23:40 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/02 21:55:53 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*res;

	res = dst;
	while (*dst)
		dst++;
	while (*src && n > 0)
	{
		*(dst++) = *(src++);
		n--;
	}
	*dst = '\0';
	return (res);
}
