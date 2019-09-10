/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:38:58 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/04 12:31:34 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;
	char	*cont;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if (!(cont = (char *)malloc(sizeof(char) * content_size + 1)))
			return (NULL);
		ft_memcpy(cont, content, content_size);
		node->content = (t_list *)cont;
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
