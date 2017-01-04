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
#include <stdio.h>
// get precision and get minwidth are working
int		get_precision(char *mods, va_list arglist)
{
	int		precision;
	int		count;
	char	*precis;

	count = 0;
	precis = NULL;
	if (!mods)
		return (0);
	while (*mods != '.' && *mods)
		mods++;
	if (!*mods)
		precision = 0;
	mods++;
	if (*mods == '*')
		precision = va_arg(arglist, int);
	else
	{
		while (ft_isdigit(mods[count]) == 1 && mods[count])
			count++;
		precis = ft_strsub(mods, 0, count);
		if (!precis)
			precision = 0;
		else
			precision = ft_atoi(precis);
	}
	return (precision);
}

int		get_minwidth(char *mods, va_list arglist)
{
	int		minwidth;
	int		count;
	char	*minw;

	count= 0;
	minw = NULL;
	if (!mods)
		return (0);
	while (ft_isdigit(*mods) != 1 && *mods != '.' && *mods != '*' && *mods)
		mods++;
	if (!*mods || *mods == '.')
		minwidth = 0;
	else if (*mods == '*')
		minwidth = va_arg(arglist, int);
	else
	{
		while (ft_isdigit(mods[count]) == 1 && mods[count])
			count++;
		minw = ft_strsub(mods, 0, count);
		if (!minw)
			minwidth = 0;
		else
			minwidth = ft_atoi(minw);
	}
	return (minwidth);
}

char	get_pad(char *mods)
{
	char	pad;

	while (ft_isdigit(*mods) != 1)
		mods++;
	if (*mods == '0')
		pad = '0';
	else
		pad = ' ';
	return (pad);
}

/*
** WHERE 1 MEANS LEFT JUSTIFY AND 0 MEANS RIGHT JUSTIFY
*/

int		get_justify(char *mods)
{
	while (*mods)
	{
		if (*mods == '-')
			return (1);
		mods++;
	}
	return (0);
}

// int		get_sign(char *mods)
// {
// 	int		b;
// 	int		b2;

// 	b = 0;
// 	b2 = 0;
// 	while (*mods++ && !b)
// 	{
// 		if (*mods == '+')
// 			b = 1;
// 		if (*mods == ' ')
// 			b2 = 2;
// 	}
// 	if (b)
// 		return (b);
// 	if (b2)
// 		return (b2);
// 	else
// 		return (0);
// }
