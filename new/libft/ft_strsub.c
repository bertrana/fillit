/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:09:54 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/06 11:59:37 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (!len && !start)
		return ("");
	if (len + 1 < len)
		return (NULL);
	if (!(res = ft_memalloc(len + 1)))
		return (NULL);
	return (ft_strncpy(res, (char*)s + start, len));
}
