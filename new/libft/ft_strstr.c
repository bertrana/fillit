/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:13:25 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 17:47:03 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *haystack, const char *needle)
{
	const char		*ptr;
	size_t			len;

	if (!*needle)
		return ((char *)haystack);
	ptr = haystack;
	len = ft_strlen(needle);
	while ((ptr = ft_strchr(ptr, *needle)))
	{
		if (!ft_strncmp(ptr, needle, len))
			return (char *)ptr;
		ptr++;
	}
	return (NULL);
}
