#include "minishell.h"

char	**ft_parce_line(char *line)
{
	char **split;

	split = ft_strsplit(line, ';');
	return (split);
}
