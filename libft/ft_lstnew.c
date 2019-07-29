#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->content = (void *)content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
