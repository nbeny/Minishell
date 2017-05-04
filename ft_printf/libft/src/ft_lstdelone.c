#include "../include/libft.h"

void	ft_lstdelone(t_lib **alst, void (*del)(void*, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
