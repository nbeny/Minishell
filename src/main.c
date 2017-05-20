#include "minishell.h"

void	ft_print_env(t_env *e, int nb, int i, int free)
{
	t_env	*s;
	t_env	*f;

	s = e;
	f = e;
	if (e != NULL)
	{
		while (free == 1 && s && s->name != NULL)
		{
			ft_printf(0, "%s=%s\n", s->name, s->value);
			s = s->next;
		}
		if (i == 1 && f != NULL)
			ft_free_env(f);
		else if (i == 0 && nb != 0)
			f = ft_env_opt_i(f, nb);
	}
}

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
		ft_free_exe(exec);
		ft_strdel(&line);
	}
	ft_free_env(e);
	return (0);
}
