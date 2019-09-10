/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:34:35 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 20:34:37 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long a;
	long l;

	a = n;
	if (a == 0)
		ft_putchar_fd('0', fd);
	else if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	l = 1;
	while (l <= a)
		l = l * 10;
	l /= 10;
	while (l)
	{
		ft_putchar_fd((a / l) + '0', fd);
		a %= l;
		l /= 10;
	}
}
