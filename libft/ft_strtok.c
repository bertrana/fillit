/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:33:36 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 21:36:03 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtok(char *str, const char *sep)
{
	static char	*lasts;
	int			ch;

	if (!str)
		str = lasts;
	if (!(ch = *str))
		return (NULL);
	str++;
	while (ft_strchr(sep, ch))
	{
		if (!(ch = *str))
			return (NULL);
		str++;
	}
	--str;
	lasts = str + ft_strcspn(str, sep);
	if (*lasts)
		*lasts++ = '\0';
	return (str);
}
