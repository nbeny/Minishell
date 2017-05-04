#include "../include/libft.h"

void	ft_lstadd(t_lib **alst, t_lib *new)
{
	new->next = *alst;
	*alst = new;
}
