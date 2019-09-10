/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:45:41 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 16:56:27 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(str);
	if (len + 1 < len)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	ft_strcpy(dest, str);
	return (dest);
}
