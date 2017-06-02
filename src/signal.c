/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:25:15 by nbeny             #+#    #+#             */
/*   Updated: 2017/06/02 14:25:19 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_exe(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, sig_exe);
	}
}

void	sig_init(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n\033[34;1m$> \033[0m");
		signal(SIGINT, sig_init);
	}
}
