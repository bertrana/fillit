/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:24:00 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 17:30:19 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	if (!dest || !src)
		return (0);
	len = ft_strlen(src);
	if (len + 1 < len)
		return (0);
	if (len + 1 < size)
		ft_memcpy(dest, src, len + 1);
	else if (size)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}
