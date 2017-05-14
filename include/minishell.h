#ifndef MINISHELL_H
# define MINISHELL_H

#include "../ft_printf/include/ft_printf.h"
#include <unistd.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}			t_env;

typedef struct	s_exec
{
	char			**cmd;
	int				i;
	struct s_exec	*next;
}			t_exec;

/*
**main
*/
int		main(int ac, char **av, char **env);
/*
**get_env
*/
t_env	*ft_get_env(char **env);
int		ft_equal(char *s);
/*
**parcing
*/
t_exec	*ft_cmd_parcing(char *line);
t_exec	*ft_multicmd(t_exec *exe);
/*
**make
*/

#endif
