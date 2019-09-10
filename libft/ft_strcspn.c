/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:39:52 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 21:41:50 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strcspn(const char *cs, const char *ct)
{
	size_t		n;

	n = 0;
	while (*cs)
	{
		if (ft_strchr(ct, *cs))
			return (n);
		else
		{
			n++;
			cs++;
		}
	}
	return (n);
}
