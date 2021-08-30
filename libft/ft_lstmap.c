
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *lstnew;
	t_list *newtmp;

	if (!lst || !f || !del)
		return (NULL);
	newtmp = NULL;
	while (lst)
	{
		if (!(newtmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, newtmp);
		lst = lst->next;
	}
	return (lstnew);
}
