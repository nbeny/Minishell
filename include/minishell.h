#ifndef MINISHELL_H
# define MINISHELL_H

#include "../ft_printf/include/ft_printf.h"
#include <unistd.h>

typedef struct	s_path
{
	char			*cmd;
	char			**opt;
	int			i;
	struct s_path	next;
}			t_path;

typedef struct	s_shell
{
	int	pt_vir;
}			t_shell;

int	main(int ac, char **av, char **env);
#endif
