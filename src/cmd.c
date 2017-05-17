#include "minishell.h"
/*
void	ft_cd(t_exec *exe, t_env *e)
{
	
}

void	ft_pwd(t_exec *exe, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;

	pid = fork();
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		status = execve("/bin/pwd", exe->cmd, env);
		exit(status);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
}
*/
void	ft_execute(t_exec *exe, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	char	*s;

	pid = fork();
	s = ft_strjoin(ft_getenv(e, "PWD\0", 4), &(exe->cmd)[0][1]);
	env = ft_list_to_tab(e);
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		status = execve(s, exe->cmd, env);
		exit(status);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
	ft_strdel(&s);
	ft_free_tabstr(env);
}
