
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		list->content = NULL;
	else
	{
		if (!(list->content = malloc(sizeof(*content))))
			return (NULL);
		list->content = content;
	}
	list->next = NULL;
	return (list);
}
