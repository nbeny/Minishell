#include "../include/libft.h"

int		ft_countstr(char **s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != NULL && s[i][0] != c)
		i++;
	return (i);
}
