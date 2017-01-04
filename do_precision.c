/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:25:31 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/15 16:25:32 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
//precision is actually performed before justifications

static  char	*pad_copy(char* original, int sign, int pad, int totallen)
{
	char	*ret;
	int		count;

	count = 0;
	ret = (char*)malloc(sizeof(char) * totallen);
		if (!ret)
			return (NULL);
	if (sign)
	{
		ret[0] = '-';
		count++;
	}
	while (count - sign < pad)
	{
		ret[count] = '0';
		count++;		
	}
	while (*original)
	{
		ret[count] = *original;
		count++;
		original++;
	}
	ret[totallen] = '\0';
	return (ret);
}

char			*do_precision(char	*output, int precision)
{
	int		len;
	int		count;
	int 	minussign;
	char	*retoutp;

	len = 0;
	count = 0;
	minussign = (output[0] == '-' ? 1 : 0);
	if (minussign)
		output++;
	len = ft_strlen(output);
	if (len < precision)
	{
		len = precision - len; // how many zeros we will add
		precision += minussign; // total lenght to allocate
		retoutp = pad_copy(output, minussign, len, precision);

	}
	if (minussign)
		output--;
	if (len >= precision)
		retoutp = ft_strdup(output);
	free(output);
	return (retoutp);
}
