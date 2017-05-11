#include "minishell.h"

t_shell	*ft_init_shell(void)
{
	t_shell	*shell;

	if (!(shell = (t_shell *)malloc(sizeof(t_shell))))
		return (NULL);
	shell->pt_vir = 0;
	shell->first_list = 0;
	shell->size_opt = 0;
	return (shell);
}

int		main(int ac, char **av)
{
	char	*line;
	t_path	*path;
	t_shell	*shell;

	(void)ac;
	(void)av;
	shell = ft_init_shell();
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (line[0] != '\0')
		{
			path = ft_parce_line(line, shell);
			ft_putchar('\n');
		}

	}
	return (0);
}
