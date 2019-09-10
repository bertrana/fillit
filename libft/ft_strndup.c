/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:57:40 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 17:02:43 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;

	if (n + 1 < n)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(dest, s1, n);
	return (dest);
}
