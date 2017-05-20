#include "../include/libft.h"

void	ft_lstdel(t_lib **alst, void (*del)(void*, size_t))
{
	if (alst != NULL)
	{
		while ((*alst)->next != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = (*alst)->next;
		}
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
