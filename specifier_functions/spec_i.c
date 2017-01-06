/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:34:56 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:34:59 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// -32769 short = max short wrap
// -9223372036854775808 max long long no wrap 9223372036854775807
// get minwidth is working
static char	*get_output(char *mods, va_list arglist, int precision)
{
	int		len;
	char	*ret;

	len = get_len(mods);
	if (len == L)
		ret = ft_lltoa(va_arg(arglist, long));
	else if (len == LL)
		ret = ft_lltoa(va_arg(arglist, long long));
	else if (len == J)
		ret = ft_lltoa(va_arg(arglist, intmax_t));
	else if (len == Z)
		ret = ft_lltoa(va_arg(arglist, size_t));
	else if (len == HH)
		ret = hh_spec(arglist);
	else if (len == H)
		ret = h_spec(arglist);
	else
		ret = ft_itoa(va_arg(arglist, int));
	if (ret[0] == '0' && ret[1] == '\0' && precision == 0) // dealing with weird case
		ret[0] = 0;
	return (ret);
}

int			spec_i(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	output = get_output(mods, arglist, precision);
	if (!output)
		return (0);
//	if (checkthrough_for(mods, '-') == 0)
	output = do_precision(output, precision);
	if (!output)
		return (0);
	output = do_minwidth(output, minwidth, mods, 'i');
	if (!output)
		return (0);
	retlen = printf_free(output);
	return (retlen);
}
