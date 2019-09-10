/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:37:38 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 10:56:05 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		any;

	any = 0;
	sign = 0;
	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		sign++;
	if (*str == '-' || *str == '+')
		str++;
	str--;
	while (*(++str) && ft_isdigit(*str))
		if (any < 0 || res > LONG_MAX / 10 ||
				(res == LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10))
			any = -1;
		else
			res = res * 10 + (*str - '0');
	if (any < 0)
		res = (!sign) ? -1 : 0;
	else
		res = ((sign) ? -res : res);
	return (res);
}
