/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:31:01 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 11:09:37 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_calloc(size_t count, size_t size)
{
	size_t	alloc_size;
	void	*new;

	alloc_size = count * size;
	if (size && ((alloc_size) / size != count))
		return (NULL);
	new = malloc(alloc_size);
	if (new)
	{
		ft_memset(new, 0, alloc_size);
		return (new);
	}
	return (NULL);
}
