#include "minishell.h"

int	ft_equal(char *s)
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

t_env	*ft_get_env_next(char **env, t_env *e)
{
	e->user = ft_strdup(&env[17][ft_equal(env[17])]);
	e->xpc_service_name = ft_strdup(&env[18][ft_equal(env[18])]);
	e->logname = ft_strdup(&env[19][ft_equal(env[19])]);
	e->iterm_session_id = ft_strdup(&env[20][ft_equal(env[20])]);
	e->__cf_user_name_encoding = ft_strdup(&env[21][ft_equal(env[21])]);
	e->shlvl = ft_strdup(&env[22][ft_equal(env[22])]);
	e->oldpwd = ft_strdup(&env[23][ft_equal(env[23])]);
	e->zsh = ft_strdup(&env[24][ft_equal(env[24])]);
	e->pager = ft_strdup(&env[25][ft_equal(env[25])]);
	e->less = ft_strdup(&env[26][ft_equal(env[26])]);
	e->lscolors = ft_strdup(&env[27][ft_equal(env[27])]);
	e->_ = ft_strdup(&env[28][ft_equal(env[28])]);
	return (e);
}

t_env	*ft_get_env(char **env)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->term_session_id = ft_strdup(&env[0][ft_equal(env[0])]);
	e->ssh_auth_sock = ft_strdup(&env[1][ft_equal(env[1])]);
	e->apple_pubsub_socket_render = ft_strdup(&env[2][ft_equal(env[2])]);
	e->colorfgbg = ft_strdup(&env[3][ft_equal(env[3])]);
	e->iterm_profile = ft_strdup(&env[4][ft_equal(env[4])]);
	e->xpc_flags = ft_strdup(&env[5][ft_equal(env[5])]);
	e->pwd = ft_strdup(&env[6][ft_equal(env[6])]);
	e->shell = ft_strdup(&env[7][ft_equal(env[7])]);
	e->securitysessionid = ft_strdup(&env[8][ft_equal(env[8])]);
	e->lc_ctype = ft_strdup(&env[9][ft_equal(env[9])]);
	e->term_program_version = ft_strdup(&env[10][ft_equal(env[10])]);
	e->term_program = ft_strdup(&env[11][ft_equal(env[11])]);
	e->path = ft_strdup(&env[12][ft_equal(env[12])]);
	e->command_mode = ft_strdup(&env[13][ft_equal(env[13])]);
	e->term = ft_strdup(&env[14][ft_equal(env[14])]);
	e->home = ft_strdup(&env[15][ft_equal(env[15])]);
	e->tmpdir = ft_strdup(&env[16][ft_equal(env[16])]);
	e = ft_get_env_next(env, e);
	return (e);
}
