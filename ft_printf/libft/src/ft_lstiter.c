#include "../include/libft.h"

void	ft_lstiter(t_lib *lst, void (*f)(t_lib *elem))
{
	int		i;

	i = 0;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			f(lst);
			lst = lst->next;
		}
		f(lst);
	}
}
