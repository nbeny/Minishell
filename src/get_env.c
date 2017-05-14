#include "minishell.h"

int		ft_equal(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && s[i] != '=')
			i++;
		if (s[i] == '=')
			return (i + 1);
	}
	return (0);
}

t_env	*ft_get_env(char **env)
{
	t_env	*e;
	t_env	*s;
	int		i;

	i = 0;
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->name = ft_strsub(env[i], 0, (ft_equal(env[i]) - 1));
	e->value = ft_strdup(&env[i][ft_equal(env[i])]);
	s = e;
	while (env[i] != NULL)
	{
		if (!(s->next = (t_env *)malloc(sizeof(t_env))))
			return (NULL);
		s->name = ft_strsub(env[i], 0, (ft_equal(env[i]) - 1));
		s->value = ft_strdup(&env[i][ft_equal(env[i])]);
		i++;
		s = s->next;
	}
	s->next = NULL;
	return (e);
}
