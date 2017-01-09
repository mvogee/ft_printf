/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_up_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:36:44 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:36:45 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	special_print(char *output)
{
	int	len;

	len = ft_strlen(output);
	write(1, output, len);
	write(1, "\0", 1);
	ft_memdel((void**)&output);
	return (len);
}

static int	givennull(char *output, int minwidth, char *mods)
{
	int retlen;

	retlen = 0;
	output = do_minwidth(output, minwidth, mods, 'c');
	if (!output)
		return (0);
	retlen = special_print(output);
	return (retlen);
}

int			spec_up_c(char *mods, va_list arglist)
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
	output = ft_uni_utf8_char(va_arg(arglist, wchar_t));
	if (!output)
		return (0);
	if (output[0] == '\0' && minwidth > 1)
		retlen = givennull(output, minwidth - 1, mods);
	else
	{
		output = do_minwidth(output, minwidth, mods, 'C');
		if (!output)
			return (0);
		retlen = printf_free(output);
	}
	return (retlen);
}
