#include "minishell.h"

void	ft_freestyle(t_exec *exe)
{
	t_exec	*s;
	int		i;

	i = 0;
	s = exe;
	while (exe->cmd[i] != NULL)
	{
		ft_strdel(&(exe->cmd)[i++]);
		exe->cmd = NULL;
	}
	free(exe->cmd);
	exe->cmd = NULL;
	free(exe);
	exe = NULL;
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
