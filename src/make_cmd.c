#include "minishell.h"

void	ft_ls(t_exec *exe, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	int		i;

	pid = fork();
	env = ft_list_to_tab(e);
	i = 0;
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		status = execve("/bin/ls", exe->cmd, env);
		exit(EXIT_SUCCESS);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
}

void	ft_env(t_exec *exe, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	int		i;

	pid = fork();
	env = ft_list_to_tab(e);
	i = 0;
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		status = execve("/usr/bin/env", exe->cmd, env);
		exit(status);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
}

void	ft_echo(t_exec *exe, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	int		i;

	pid = fork();
	env = ft_list_to_tab(e);
	i = 0;
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		status = execve("/bin/echo", exe->cmd, env);
		exit(status);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
}

void	ft_w(t_exec *exe, t_env *e)
{
	pid_t	pid;
	pid_t	w;
	int		status;
	char	**env;
	int		i;

	pid = fork();
	env = ft_list_to_tab(e);
	i = 0;
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		status = execve("/usr/bin/w", exe->cmd, env);
		exit(status);
	}
	else
	{
		w = waitpid(pid, &status, WCONTINUED);
		if (w == -1)
			exit(EXIT_FAILURE);
	}
}

int		ft_make_cmd(t_exec *exe, t_env *e)
{
	e->i = 0;
	if (exe->cmd[0] == NULL)
		return (0);
	if (!ft_strncmp(exe->cmd[0], "exit\0", 5))
		exit(EXIT_SUCCESS);
	else if (!ft_strncmp(exe->cmd[0], "env\0", 4))
		ft_env(exe, e);
	/*
	  else if (!ft_strncmp(exe->cmd[0], "setenv\0", 7))
	  ft_execute(exe, e);
	  else if (!ft_strncmp(exe->cmd[0], "unsetenv\0", 9))
	  ft_execute(exe, e);
	  else if (!ft_strncmp(exe->cmd[0], "pwd\0", 4))
	  ft_execute(exe, e);
	  else if (!ft_strncmp(exe->cmd[0], "cd\0", 3))
	  ft_execute(exe, e);
	*/
	else if (!ft_strncmp(exe->cmd[0], "ls\0", 3))
		ft_ls(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "echo\0", 5))
		ft_echo(exe, e);
	else if (!ft_strncmp(exe->cmd[0], "w\0", 2))
		ft_w(exe, e);
	/*
	  else if (!ft_strncmp(exe->cmd[0], "./", 2))
	  ft_execute(exe, e);
	*/
	else
		ft_printf(2, "command not found: %s\n", exe->cmd[0]);
	return (1);
}
