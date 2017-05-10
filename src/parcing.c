#include "minishell.h"

t_path	*ft_init_path(t_path *path)
{
	t_path *path;

	if (!((t_path *)malloc(sizeof(t_path))))
		return (NULL);
	path->i = 0;
	path->cmd = NULL;
	path->opt = NULL;
	return (path);
}

t_path	*ft_parce_line(char *line, t_path *path, t_shell *shell)
{
	char	**split;
	int		i;
	int		p;


	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
	{
		p = i;
		path = ft_init_path(path);
		while (split[i] != NULL && split[i] != ';')
		{
			if (p == i && (ft_strcmp(split[i], "cd\0") || ft_strcmp(split[i], "pwd\0") ||
				ft_strcmp(split[i], "ls\0") || ft_strcmp(split[i], "env\0") ||
				ft_strcmp(split[i], "setenv\0") || ft_strcmp(split[i], "unsetenv\0") ||
				ft_strcmp(split[i], "echo\0") || ft_strcmp(split[i], "exit\0")))
				path->cmd = ft_strdup(split[i]);
			else
				path->opt[path->i++] = ft_strdup(split[i]);
			i++;
		}
		if (split[i] == ';')
			i++;
		path = path->next;
	}
	return (split);
}
