/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 10:51:53 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/07 10:51:54 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char*)ft_memalloc(len + 1)))
		return (NULL);
	ret[len] = '\0';
	len = 0;
	while (s1 && *s1)
	{
		ret[len] = *s1;
		len++;
		s1++;
	}
	while (s2 && *s2)
	{
		ret[len] = *s2;
		len++;
		s2++;
	}
	return (ret);
}
