/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:32:49 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/15 18:32:50 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

char	*ft_strdup(char *str)
{
	int 	len;
	int		count;
	char	*ret;

	len = ft_strlen(str);
	count = 0;
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (*str++)
	{
		ret[count] = *str;
		count++;
	}
	ret[len] = '\0';
	return (ret);
}
