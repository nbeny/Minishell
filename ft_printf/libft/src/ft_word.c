#include "../include/libft.h"

int		ft_word(char *s, int i)
{
	if (s)
	{
		while (s[i] && ft_isprint(s[i]) &&
			s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i++;
	}
	return (i);
}
