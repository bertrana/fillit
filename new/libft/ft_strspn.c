/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:38:29 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/08 13:56:25 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strspn(const char *cs, const char *ct)
{
	int	i;
	int j;

	i = 0;
	while (cs[i])
	{
		j = 0;
		while (ct[j])
		{
			if (ct[j] == cs[i])
				break ;
			j++;
		}
		if (!ct[j])
			break ;
		i++;
	}
	return (i);
}
