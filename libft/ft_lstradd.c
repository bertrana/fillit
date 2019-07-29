#include "libft.h"

t_list				*ft_lstradd(t_list *alst, t_list *new)
{
	t_list	*start;

	start = alst;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
	return (start);
}