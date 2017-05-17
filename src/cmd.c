#include "minishell.h"

void	ft_cd(t_exec *exe, t_env *e)
{
	t_env	*home;
	t_env	*pwd;
	t_env	*oldpwd;

	if (e == NULL)
		return ;
	pwd = ft_moove_env(e, "PWD\0", 4);
	oldpwd = ft_moove_env(e, "OLDPWD\0", 7);
	home = ft_moove_env(e, "HOME\0", 5);
	if (exe->cmd[1] == NULL && !access(home->value, W_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel((&pwd->value));
		pwd->value = ft_strdup(getcwd(home->value, ft_strlen(home->value)));
	}
	else if (!access(exe->cmd[1], W_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel(&(pwd->value));
		pwd->name = ft_strdup(exe->cmd[1]);
	}
}
/*
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
