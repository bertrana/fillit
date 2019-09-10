/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:27:31 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 10:54:34 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*tmp;
	int			c;
	int			sc;

	if (!s1 || !s2)
		return (NULL);
	while ((c = (int)(*s1++)))
	{
		tmp = s2;
		while ((sc = (int)(*tmp++)))
			if (c == sc)
				return ((char *)(s1 - 1));
	}
	return (NULL);
}
