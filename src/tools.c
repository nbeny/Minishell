#include "minishell.h"

t_env   *ft_moove_env(t_env *e, char *str, int i)
{
	t_env   *s;
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

t_env	*ft_create_elem(char *name, char *value)
{
	t_env *env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (name == NULL)
		env->name = NULL;
	else
		env->name = ft_strdup(name);
	if (value == NULL)
		env->value = ft_strdup(value);
	else
		env->next = NULL;
	return (env);
}

t_env	*ft_list_push_back(t_env *begin_list, char *name, char *value)
{
	t_env	*tmp;
	t_env	*elem;

	elem = ft_create_elem(name, value);
	if (begin_list)
	{
		tmp = begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		begin_list = elem;
	return (begin_list);
}
