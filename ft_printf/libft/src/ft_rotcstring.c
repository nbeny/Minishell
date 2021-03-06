/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotcstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:05:18 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/16 14:05:22 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_rotcstring(char *s)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (s[j])
	{
		s[i] = s[j];
		i++;
		j++;
	}
	s[i] = 0;
	return (s);
}
