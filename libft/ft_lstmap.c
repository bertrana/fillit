/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:07:35 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 11:24:49 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;

	if (f && *f && lst)
	{
		if (!(node = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		node = f(lst);
		node->next = ft_lstmap(lst->next, *f);
		return (node);
	}
	return (NULL);
}
