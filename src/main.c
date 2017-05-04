#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;

	(void)ac;
	(void)av;
	while (42)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		if (line[0] != '\0')
		{
			env = ft_parce_line(line);
			ft_get_cmd(env);
			ft_putchar('\n');
		}

	}
	return (0);
}
