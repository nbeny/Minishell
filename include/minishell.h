/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:09:56 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:10:52 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <signal.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;
typedef struct	s_exec
{
	char			**cmd;
	int				i[4];
	struct s_exec	*next;
}				t_exec;

/*
**main
*/
t_exec			*ft_init_exe(t_exec *exe);
void			sig_init(int sig);
void			ft_print_env(t_env *e, int nb, int i, int free);
int				main(int ac, char **av, char **env);
t_env			*ft_shlvl(t_env *e);
/*
**tools
*/
t_env			*ft_tab_to_list(char **env);
char			**ft_list_to_tab(t_env *e);
char			*ft_getenv(t_env *e, char *s, int i);
int				ft_equal(char *s);
int				ft_listsize(t_env *e);
/*
**free
*/
void			ft_free_exe(t_exec *exe);
void			ft_free_env(t_env *e);
t_env			*ft_free_oneenv(t_env *e, t_env *s, t_env *b);
void			ft_free_tabstr(char **tab);
t_exec			*ft_cmd_parcing(char *line);
/*
**execute
*/
char			*ft_path_istrue(char **cmd, t_env *e);
void			ft_execute_path(char *str, char **cmd, t_env *e);
void			ft_execute(char **cmd, t_env *e);
void			ft_exit(t_exec *exe, t_env *e);
t_env			*ft_make_cmd(t_exec *exe, t_env *e);
/*
**bultin
*/
t_env			*ft_cd(t_exec *exe, t_env *e);
t_env			*ft_setenv(t_exec *exe, t_env *e);
t_env			*ft_unsetenv(t_exec *exe, t_env *e);
void			ft_env(t_exec *exe, t_env *e);
void			ft_echo(t_exec *exe);
/*
**cd
*/
void			ft_old(t_exec *exe, t_env *oldpwd, t_env *pwd);
void			ft_null(t_env *pwd, t_env *oldpwd, t_env *home);
void			ft_slash(t_exec *exe, t_env *pwd, t_env *oldpwd);
void			ft_home(t_exec *exe, t_env *pwd, t_env *oldpwd, t_env *home);
void			ft_modif_path(t_exec *exe, t_env *pwd, t_env *oldpwd);
/*
**env
*/
t_env			*ft_moove_env(t_env *env, char *str, int i);
t_env			*ft_env_opt_i(t_env *e, int size);
t_env			*ft_add_env(t_exec *exe, t_env *e, int i, int size);
t_env			*ft_create_elem(char *name, char *value);
t_env			*ft_list_push_back(t_env *begin_list, char *name, char *value);
/*
**norme
*/
void			ft_error_cd(t_env *pwd, t_env *oldpwd, t_env *home,\
							t_exec *exe);
char			*ft_string_return(t_env *e, char **cmd);
void			ft_error_and_make_exe(t_exec *exe, t_env *e);
t_exec			*ft_first_struct_exe(char **split);
t_exec			*ft_all_struct_exe(t_exec *exe, char **split);
#endif
