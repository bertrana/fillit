/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:05:44 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/04 14:01:24 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;

	if (!s1 || !s2)
		return (0);
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (*s1 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if ((*s1 == *s2) || !n)
		return (1);
	return (0);
}
