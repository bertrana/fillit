/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:33:59 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 11:21:19 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_count(long n)
{
	int			count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	if (count == 0)
		count++;
	return (count);
}

char			*ft_itoa(int n)
{
	char		*s;
	int			sign;
	int			count;
	long		a;

	sign = 0;
	a = (long)n;
	if (a < 0)
	{
		a = -a;
		sign = 1;
	}
	count = ft_count(a) + sign;
	if (!(s = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	s[count] = '\0';
	while (--count > -1)
	{
		s[count] = a % 10 + '0';
		a /= 10;
	}
	if (sign == 1)
		s[0] = '-';
	return (s);
}
