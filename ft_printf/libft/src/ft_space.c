#include "../include/libft.h"

int		ft_space(char *s, int i)
{
	if (s)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
	}
	return (i);
}
