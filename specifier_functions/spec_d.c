/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:32:38 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:32:39 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

// -32769 short = max short wrap
// -9223372036854775808 max long long no wrap 9223372036854775807
// get minwidth is working
static char	*get_output(char *mods, va_list arglist)
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
	return (ret);
}

// all signing will be done in do_minwidth
int			spec_d(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods, arglist);
	precision = get_precision(mods, arglist);
	output = get_output(mods, arglist);
	if (!output)
		return (0);
	if (checkthrough_for(mods, '-') == 0)
		output = do_precision(output, precision);
	if (!output)
		return (0);
	output = do_minwidth(output, minwidth, mods, 'd'); // working on this
	if (!output)
		return (0);
	retlen = printf_free(output);
	return (retlen);
}
