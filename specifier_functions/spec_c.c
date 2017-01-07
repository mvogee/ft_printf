/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:36:32 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:36:34 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_output(char *mods, va_list arglist)
{
	int		len;
	char	*ret;

	len = get_len(mods);
	if (len == L)
		ret = ft_uni_utf8_char(va_arg(arglist, wchar_t));
	else
	{
		ret = (char*)malloc(sizeof(char) * 2);
		if (!ret)
			return (NULL);
		ret[0] = va_arg(arglist, int);
		ret[1] = '\0';
	}
	return (ret);
}

int			spec_c(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	precision = 0;
	if (checkthrough_for(mods, '.'))
		mods[get_indexof(mods, '.')] = '_';
	output = get_output(mods, arglist);
	if (!output)
		return (0);
	output = do_minwidth(output, minwidth, mods, 'c');
	if (!output)
		return (0);
	retlen = printf_free(output);
	return (retlen);
}
