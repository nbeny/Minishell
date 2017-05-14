#include "minishell.h"

t_exec	*ft_multicmd(t_exec *exe)
{
	t_exec	*new;
	t_exec	*s;
	int	i[3];

	i[2] = 0;
	i[0] = ft_countstr(exe->cmd, ';');
	exe->i = ++i[2];
	if (exe->cmd[i[0]] == NULL)
		return (exe);
	if (!(new = (t_exec *)malloc(sizeof(t_exec))))
		return (NULL);
	new->cmd = ft_multisub(exe->cmd, 0, i[0]);
	s = new;
	while (exe->cmd[i[0]] != NULL)
	{
		if (exe->cmd[i[0]][0] == ';')
			i[0]++;
		if (exe->cmd[i[0]] == NULL)
			break ;
		i[1] = i[0];
		i[1] = ft_countstr(&(exe->cmd)[i[0]], ';');
		if (!(s->next = (t_exec *)malloc(sizeof(t_exec))))
			return (exe);
		s = s->next;
		s->cmd = ft_multisub(exe->cmd, i[0], i[1]);
		i[0] = i[1];
		s->i = ++i[2];
	}
	s->next = NULL;
	new->i = i[2];
	return (new);
}

t_exec	*ft_cmd_parcing(char *line)
{
	t_exec	*exe;
	int		i;

	i = 0;
	if (!(exe = (t_exec *)malloc(sizeof(t_exec))))
		return (NULL);
	//exe = ft_check_line(line);
	exe->cmd = ft_strsplit(line, ' ');
	exe = ft_multicmd(exe);
	while (exe != NULL)
	{
		while (exe->cmd[i] != NULL)
		{
			ft_putstr(exe->cmd[i++]);
			ft_putchar('\n');
		}
		exe = exe->next;
	}
	
	return (exe);
}
