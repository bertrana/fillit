/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:59:27 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 16:41:51 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 < size)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
