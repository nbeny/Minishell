#include "minishell.h"

t_env	*ft_create_elem(char *name, char *value)
{
	t_env *env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->name = ft_strdup(name);
	env->value = ft_strdup(value);
	return (env);
}

void	ft_list_push_back(t_env **begin_list, char *name, char *value)
{
	t_env	*tmp;
	t_env	*elem;

	elem = ft_create_elem(name, value);
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		*begin_list = elem;
}
