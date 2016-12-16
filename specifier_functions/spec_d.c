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

// -32769 short = max short wrap
// -9223372036854775808 max long long no wrap 9223372036854775807
static char	*get_output(char *mods, va_list arglist)
{
	int		len;
	char	*ret;

	len = get_len(mods);
	if (len == NONE)
		ret = ft_itoa(va_arg(arglist, int));
	else if (len == L)
		ret = ft_lltoa(va_arg(arglist, long));
	else if (len == LL)
		ret = ft_lltoa(va_arg(arglist, long long));
	else if (len = J)
		ret = ft_lltoa(va_arg(arglist, intmax_t));
	else if (len == Z)
		ret = ft_lltoa(va_arg(arglist, size_t));
	else if (len == HH)
		ret = hh_spec(arglist);
	else if (len == H)
		ret = h_spec(arglist);
	return (ret);
}

int			spec_d(char *mods, va_list arglist)
{
	int		precision;
	int		minwidth;
	int		retlen;
	char	*output;

	minwidth = get_minwidth(mods);
	precision = get_precision(mods);
	output = get_output(mods, arglist);
	if (!output)
		return (0);
	output = do_precision(output, precision, mods); // make this
	output = do_minwidth(output, minwidth, mods); // make this
	retlen = printf_free(output); //make this
	return (0);
}
