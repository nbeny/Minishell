#ifndef MINISHELL_H
# define MINISHELL_H

#include "../ft_printf/include/ft_printf.h"
#include <unistd.h>

typedef struct	s_path
{
	char			*cmd;
	char			**opt;
	int				i;
	struct s_path	*next;
}			t_path;

typedef struct	s_shell
{
	int     pt_vir;
	int	first_list;
	int	size_opt;
}			t_shell;

int		main(int ac, char **av);
t_shell	*ft_init_shell(void);
t_path	*ft_init_path(t_shell *shell, t_path *path);
t_path	*ft_parce_line(char *line, t_shell *shell);
#endif
