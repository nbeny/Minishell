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

t_env	*ft_setenv(t_exec *exe, t_env *e)
{
	t_env	*s;

	s = e;
	if (e != NULL && exe != NULL)
	{
		while (s != NULL && !ft_strncmp(s->name, exe->cmd[1],\
										ft_strlen(exe->cmd[1])))
			s = s->next;
		if (s != NULL)
		{
			ft_strdel(&(s->value));
			s->value = ft_strdup(exe->cmd[2]);
		}
		else if (s == NULL && exe->cmd[1] != NULL)
			ft_list_push_back(&e, exe->cmd[1], exe->cmd[2]);
		else
			ft_env(exe, e);
	}
	return (e);
}

t_env	*ft_unsetenv(t_exec *exe, t_env *e)
{
	t_env	*s;
	t_env	*b;

	s = e;
	b = e;
	if (e != NULL && exe != NULL)
	{
		s = ft_moove_env(e, exe->cmd[1], ft_strlen(exe->cmd[1]));
		if (s != NULL)
		{
			while (b->next != NULL && !ft_strncmp(b->next->name, \
										exe->cmd[1], ft_strlen(exe->cmd[1])))
				b = b->next;
			e = ft_free_oneenv(e, s, b);
		}
	}
	return (e);
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
