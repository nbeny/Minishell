#ifndef MINISHELL_H
# define MINISHELL_H

#include "../ft_printf/include/ft_printf.h"
#include <unistd.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	int				i;
	struct s_env	*next;
}			t_env;

typedef struct	s_exec
{
	char	**cmd;
}			t_exec;

/*
**main
*/
int		main(int ac, char **av, char **env);
/*
**get_env
*/
t_env	*ft_tab_to_list(char **env);
char	**ft_list_to_tab(t_env *e);
char	*ft_getenv(t_env *e, char *s, int i);
int		ft_equal(char *s);
int		ft_listsize(t_env *e);
/*
**parcing
*/
t_exec	*ft_cmd_parcing(char *line);
void	ft_free_tabstr(char **tab);
/*
**make
*/
int		ft_make_cmd(t_exec *exe, t_env *e);
void	ft_ls(t_exec *exe, t_env *e);
void	ft_env(t_exec *exe, t_env *e);
void	ft_echo(t_exec *exe, t_env *e);
void	ft_w(t_exec *exe, t_env *e);
/*
**cmd
*/
void	ft_cd(t_exec *exe, t_env *e);
void	ft_execute(t_exec *exe, t_env *e);
#endif
