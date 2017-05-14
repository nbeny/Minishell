#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*e;
	t_exec	*exec;

	(void)ac;
	(void)av;
	e = ft_get_env(env);
	while (e->next != NULL)
	{
		ft_printf("%s=%s\n", e->name, e->value);
		e = e->next;
	}
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		exec = ft_cmd_parcing(line);
	}
	return (0);
}
