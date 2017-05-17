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
