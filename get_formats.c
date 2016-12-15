/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:38:15 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 20:38:16 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_precision(char *mods)
{
	int		precision;
	int		count;
	char	*precis;

	count = 0;
	precis = NULL;
	while (*mods != '.' && *mods)
		mods++;
	mods++;
	if (!*mods)
		precision = 0;
	//mods++;
	// if (*mods == '*')
	// 	precision = ft_itoa(va_arg(arglist, int));
	else
	{
		while (mods[count] >= '0' && mods[count] <= '9' && mods[count])
			count++;
		precis = ft_strsub(mods, 0, count);
		if (!precis)
			precision = 0;
		else
			precision = ft_atoi(precis);
	}
	return (precision);
}

#include <stdio.h>
int main(void)
{
	int k = get_precision("4578.10");
	printf("%d\n", k);
	return (0);
}