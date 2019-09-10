/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:49:51 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/09 21:52:47 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetadd(t_tet **alst, t_tet *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_tet		*tetnew(int id, int a)
{
	t_tet	*node;
	char	*cont;

	if (!(node = (t_tet *)malloc(sizeof(t_tet))))
		return (NULL);
	node->id = id;
	node->fig = a;
	node->next = NULL;
	return (node);
}

void	tetclr(t_tet **lst)
{
	t_tet	*next;
	t_tet	*item;

	item = *lst;
	while (item != NULL)
	{
		next = item->next;
		free(item);
		item = next;
	}
	*lst = NULL;
}