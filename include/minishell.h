#ifndef MINISHELL_H
# define MINISHELL_H

#include "../ft_printf/include/ft_printf.h"
#include <unistd.h>

typedef struct	s_env
{
	char	*term_session_id;
	char	*ssh_auth_sock;
	char	*apple_pubsub_socket_render;
	char	*colorfgbg;
	char	*iterm_profile;
	char	*xpc_flags;
	char	*pwd;
	char	*shell;
	char	*securitysessionid;
	char	*lc_ctype;
	char	*term_program_version;
	char	*term_program;
	char	*path;
	char	*command_mode;
	char	*term;
	char	*home;
	char	*tmpdir;
	char	*user;
	char	*xpc_service_name;
	char	*logname;
	char	*iterm_session_id;
	char	*__cf_user_name_encoding;
	char	*shlvl;
	char	*oldpwd;
	char	*zsh;
	char	*pager;
	char	*less;
	char	*lscolors;
	char	*_;
}			t_env;

typedef struct	s_shell
{
	int	i;
	int	j;
	int	nb_w;
}			t_shell;

typedef struct	s_exec
{
	char			*cmd;
	char			**opt;
	int				i;
	struct s_exec	*next;
}			t_exec;

/*
**main
*/
int		main(int ac, char **av, char **env);
t_shell	*ft_init_shell(char *line, t_shell *shell);
/*
**get_env
*/
t_env	*ft_get_env(char **env);
t_env	*ft_get_env_next(char **env, t_env *e);
int		ft_equal(char *s);
/*
**parcing
*/
t_exec	*ft_cmd_parcing(char *line, t_shell *shell);
int		ft_word(char *s, t_shell *shell);
int		ft_space(char *s, t_shell *shell);
/*
**make
*/

#endif
