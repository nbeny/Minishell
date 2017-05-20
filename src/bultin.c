/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:11:03 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:11:05 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_env	*ft_setenv(t_exec *exe, t_env *e)
{
	t_env	*s;

	s = e;
	if (e != NULL && exe != NULL)
	{
		if (exe->cmd[1] != NULL && exe->cmd[2] != NULL && exe->cmd[3] != NULL)
		{
			ft_printf(2, "%s: too many arguments\n", exe->cmd[0]);
			return (e);
		}
		if (exe->cmd[1] == NULL)
			return (e);
		s = ft_moove_env(e, exe->cmd[1], (ft_strlen(exe->cmd[1]) + 1));
		if (s == NULL)
			e = ft_list_push_back(e, exe->cmd[1], exe->cmd[2]);
		else
		{
			ft_strdel(&(s->value));
			s->value = ft_strdup(exe->cmd[2]);
		}
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
		if (exe->cmd[1] != NULL && exe->cmd[2] != NULL)
		{
			ft_printf(2, "%s: too many arguments\n", exe->cmd[0]);
			return (e);
		}
		s = ft_moove_env(e, exe->cmd[1], (ft_strlen(exe->cmd[1]) + 1));
		if (s != NULL)
		{
			while (b->next != NULL && ft_strncmp(b->next->name, \
									exe->cmd[1], (ft_strlen(exe->cmd[1]) + 1)))
				b = b->next;
			e = ft_free_oneenv(e, s, b);
		}
	}
	return (e);
}

void	ft_env(t_exec *exe, t_env *e)
{
	t_env	*s;
	char	*str;

	exe = ft_init_exe(exe);
	s = e;
	while (e != NULL && exe != NULL && exe->cmd[exe->i[0]])
	{
		if ((exe->i[1] = ft_equal(exe->cmd[exe->i[0]])))
			s = ft_add_env(exe, s, exe->i[0], exe->i[1]);
		else if (!ft_strncmp(exe->cmd[exe->i[0]], "-i\0", 3))
		{
			s = ft_env_opt_i(s, exe->i[2]);
			exe->i[2] = 0;
			exe->i[3] = 1;
		}
		else if (!ft_strncmp(exe->cmd[exe->i[0]], "env\0", 4) &&\
			(str = ft_path_istrue(&exe->cmd[exe->i[0]], s)))
		{
			ft_execute_path(str, &(exe->cmd)[exe->i[0]], s);
			ft_print_env(s, exe->i[2], exe->i[3], 0);
			return ;
		}
		exe->i[0]++;
	}
	ft_print_env(s, exe->i[2], exe->i[3], 1);
}

void	ft_echo(t_exec *exe)
{
	int		i;

	i = 1;
	if (exe != NULL)
	{
		while (exe->cmd[i])
		{
			ft_putstr(exe->cmd[i]);
			if (exe->cmd[i + 1] != NULL)
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
}
