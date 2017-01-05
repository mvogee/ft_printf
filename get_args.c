/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:53:05 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/15 13:53:06 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(char *mods)
{
	if (!mods)
		return (NONE);
	while (*mods)
	{
		if (*mods == 'h' && mods[1] == 'h')
			return (HH);
		if (*mods == 'h')
			return (H);
		if (*mods == 'l' && mods[1] == 'l')
			return (LL);
		if (*mods == 'l')
			return (L);
		if (*mods == 'j')
			return (J);
		if (*mods == 'z')
			return (Z);
		mods++;
	}
	return (NONE);
}

int		make_short(int i)
{
	int		ret;

	ret = i;
	while (ret < -32768 || ret > 32767)
	{
		if (ret > 32767)
			ret = -32769 + (ret - 32767);
		else if (ret < -32768)
			ret = 32767 - (ret + 32769);
	}
	return (ret);
}

int		make_ascii(int i)
{
	int		ret;

	ret = i;
	while (ret < -128 || ret > 127)
	{
		if (ret < 0)
			ret = 127 + (ret + 129);
		else if (ret > 127)
			ret = -129 + (ret - 127);
	}
	return (ret);
}

char	*h_spec(va_list arglist)
{
	int		num;

	num = va_arg(arglist, int);
	num = make_short(num);
	return (ft_itoa(num));
}

char	*hh_spec(va_list arglist)
{
	int		num;

	num = va_arg(arglist, int);
	num = make_ascii(num);
	return (ft_itoa(num));
}
