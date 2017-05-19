#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*e;
	t_exec	*exec;

	(void)ac;
	(void)av;
	e = ft_tab_to_list(env);
	while (42)
	{
		ft_putstr("\033[34;1m$> \033[0m");
		get_next_line(0, &line);
		exec = ft_cmd_parcing(line);
		e = ft_make_cmd(exec, e);
	}
	return (0);
}
