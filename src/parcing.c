#include "minishell.h"

t_path	*ft_init_path(t_shell *shell, t_path *path)
{
	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	path->i = 0;
	path->cmd = NULL;
	if (!(path->opt = (char **)malloc(sizeof(char *) * (shell->size_opt + 1))))
	{
		free(path);
		return (NULL);
	}
	return (path);
}

t_path	*ft_parce_line(char *line, t_shell *shell)
{
	t_path	*path;
	t_path	*save;
	char	**split;
	int		i;
	int		p;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
	{
		p = i;
		while (split[i] != NULL && ft_strncmp(split[i], ";\0", 2) == 0)
		{
			shell->size_opt += 1;
			i++;
		}
		ft_putnbr(i);fflush(stdout);
		path = ft_init_path(shell, path);
		if (path == NULL)
			return (NULL);
		i = p;
		while (split[i] != NULL && ft_strncmp(split[i], ";\0", 2) != 0)
		{
			if (p == i && (ft_strncmp(split[i], "cd\0", 3) == 0 ||
					ft_strncmp(split[i], "pwd\0", 4) == 0 ||
					ft_strncmp(split[i], "ls\0", 3) == 0 ||
					ft_strncmp(split[i], "env\0", 4) == 0 ||
					ft_strncmp(split[i], "setenv\0", 7) == 0 ||
					ft_strncmp(split[i], "exit\0", 5) == 0 ||
					ft_strncmp(split[i], "echo\0", 5) == 0 ||
					ft_strncmp(split[i], "unsetenv\0", 9) == 0))
			{
				path->cmd = ft_strdup(split[i]);
				ft_printf("[%s]\n", path->cmd);fflush(stdout);
			}
			else
			{
				path->opt[path->i++] = ft_strdup(split[i]);
				ft_printf("[%s]\n", path->opt[path->i]);fflush(stdout);
			}
			i++;
		}
		path->opt[path->i] = NULL;
		if (shell->first_list == 0)
		{
			save = path;
			shell->first_list = 1;
		}
		shell->pt_vir += 1;
		i++;
		path = path->next;
	}
	path = NULL;
	return (save);
}
