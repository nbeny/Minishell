/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:10 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:12 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_old(t_exec *exe, t_env *oldpwd, t_env *pwd)
{
	char	*str;

	str = ft_strjoin(oldpwd->value, &(exe->cmd)[1][1]);
	if (chdir(str) == 0 && !access(str, R_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(getcwd(str, (ft_strlen(str) + 1)));
	}
	ft_strdel(&str);
	
}

void	ft_null(t_env *pwd, t_env *oldpwd, t_env *home)
{
	if (chdir(home->value) == 0 && !access(home->value, R_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel((&pwd->value));
		pwd->value = ft_strdup(getcwd(home->value,\
								(ft_strlen(home->value) + 1)));
	}
}

void	ft_slash(t_exec *exe, t_env *pwd, t_env *oldpwd)
{
	if (chdir(exe->cmd[1]) == 0 && !access(exe->cmd[1], R_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(getcwd(exe->cmd[1],\
								(ft_strlen(exe->cmd[1]) + 1)));
	}
}

void	ft_home(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *home)
{
	char	*str;

	str = ft_strjoin(home->value, &(exe->cmd)[1][1]);
	if (chdir(str) == 0 && !access(str, R_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(getcwd(str, (ft_strlen(str) + 1)));
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
	if (chdir(str) == 0 && !access(str, R_OK))
	{
		ft_strdel(&(oldpwd->value));
		oldpwd->value = ft_strdup(pwd->value);
		ft_strdel(&(pwd->value));
		pwd->value = ft_strdup(getcwd(str, (ft_strlen(str) + 1)));
	}
	ft_strdel(&str);
}
