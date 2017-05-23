/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 10:08:24 by nbeny             #+#    #+#             */
/*   Updated: 2017/05/20 10:08:26 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_word(char *s, int i)
{
	if (s)
	{
		while (s[i] && ft_isprint(s[i]) &&
			s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i++;
	}
	return (i);
}
