#include "../include/libft.h"

char	**ft_multisub(char **s, int start, int end)
{
	int		i[2];
	char	**new_str;

	i[0] = 0;
	i[1] = start;
	if (s == NULL)
		return (NULL);
	if (s[0] == NULL)
		return (NULL);
	if (start > end)
		return (NULL);
	if (!(new_str = (char **)malloc(sizeof(char) * (end - start + 2))))
		return(NULL);
	while (start < end && s[start] != NULL)
		new_str[i[0]++] = ft_strdup(s[start++]);
	new_str[i[0]] = NULL;
	return (new_str);		
}
