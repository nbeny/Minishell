#include "minishell.h"

t_env	*ft_cd(t_exec *exe, t_env *e)
{
	t_env	*home;
	t_env	*pwd;
	t_env	*oldpwd;

	if (e == NULL || exe == NULL)
		return (NULL);
	pwd = ft_moove_env(e, "PWD\0", 4);
	oldpwd = ft_moove_env(e, "OLDPWD\0", 7);
	home = ft_moove_env(e, "HOME\0", 5);
	if (exe->cmd[1] == NULL)
		ft_null(pwd, oldpwd, home);
	else if (exe->cmd[1][0] == '/')
		ft_slash(exe, pwd, oldpwd);
	else if (exe->cmd[1][0] == '~')
		ft_home(exe, pwd, oldpwd, home);
	else
		ft_modif_path(exe, pwd, oldpwd);
	return (e);
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
