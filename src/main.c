#include "minishell.h"

t_shell	*ft_init_shell(char *line, t_shell *shell)
{
	shell->i = 0;
	shell->j = 0;
	shell->nb_w = 0;
	return (shell);
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*e;
	t_exec	*exec;

	(void)ac;
	(void)av;
	e = ft_get_env(env);
	ft_putstr(e->pwd);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		exec = ft_cmd_parcing(line, shell);
		ft_make_cmd(shell, e, exec);
	}
	return (0);
}
