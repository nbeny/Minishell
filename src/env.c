#include "minishell.h"

t_env	*ft_moove_env(t_env *e, char *str, int i)
{
	t_env	*s;

	s = e;
	if (e != NULL)
	{
		while (s != NULL)
		{
			if (!ft_strncmp(s->name, str, i))
				return (s);
			s = s->next;
		}
	}
	return (NULL);
}

void	ft_null(t_env *pwd, t_env *oldpwd, t_env *home)
{
	if (chdir(home->value) == 0 && !access(home->value, W_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel((&pwd->value));
		pwd->value = ft_strdup(home->value);
	}
}

void	ft_slash(t_exec *exe, t_env *pwd, t_env *oldpwd)
{
	if (chdir(exe->cmd[1]) == 0 && !access(exe->cmd[1], W_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel((&pwd->value));
		pwd->value = ft_strdup(exe->cmd[1]);
	}
}

void	ft_home(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *home)
{
	char	*str;

	str = ft_strjoin(home->value, &(exe->cmd)[1][1]);
	if (chdir(str) == 0 && !access(str, W_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel((&pwd->value));
		pwd->value = ft_strdup(str);
	}
	ft_strdel(&str);
}

void	ft_modif_path(t_exec *exe, t_env *pwd, t_env *oldpwd)
{
	char	*str;
	char	*clean;

	clean = ft_strjoin(pwd->value, "/");
	str = ft_strjoin(clean, exe->cmd[1]);
	ft_strdel(&clean);
	if (chdir(str) == 0 && !access(str, W_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel((&pwd->value));
		pwd->value = ft_strdup(getcwd(str, ft_strlen(str)));
	}
	ft_strdel(&str);
}
