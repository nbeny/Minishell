#include "minishell.h"

void	ft_free_tabstr(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		if (tab[i] != NULL)
			while (tab[i] != NULL)
			{
				ft_strdel(&tab[i]);
				tab[i] = NULL;
				i++;
			}
		free(tab);
		tab = NULL;
	}
}

t_exec	*ft_cmd_parcing(char *line)
{
	t_exec	*exe;
	int		i;

	i = 0;
	if (!(exe = (t_exec *)malloc(sizeof(t_exec))))
		return (NULL);
	exe->cmd = ft_strsplit(line, ' ');
	return (exe);
}
