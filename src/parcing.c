#include "minishell.h"

int		ft_space(char *s, t_shell *shell)
{
	while (s[shell->i] != '\0' && (s[shell->i] == ' ' || s[shell->i] == '\t'))
		shell->i++;
	return (shell->i);
}

int		ft_word(char *s, t_shell *shell)
{
	while (s[shell->i] != '\0' && s[shell->i] != ' ' && s[shell->i] != '\t')
		shell->i++;
	shell->nb_w++;
	return (shell->i);
}

t_exec	*ft_cmd_parcing(char *line, t_shell *shell)
{
	t_exec	*exec;

	shell = ft_init_shell(shell);
	while (line != '\0')
	{
		ft_space(line, shell);
		ft_word(line, shell);
	}
	ft_printf("nb_w = [%i]\n", shell->nb_w);fflush(stdout);
	if (shell->nb_w == 0)
		return (NULL);
	if (shell->nb_w >= 1)
	{
		ft_strsplit(line, (' ' || '\t'));
		if (shell->nb_w == 1 && ft_true_cmd())
			exec = ft_memcmd(exec, );
	}
		
}
