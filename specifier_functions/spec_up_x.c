/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_up_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:36:17 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:36:18 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*strtoupper(char *str)
{
	int count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count])
	{
		if (str[count] >= 'a' && str[count] <= 'z')
			str[count] -= 32;
		count++;
	}
	return (str);
}

static char	*get_output(char *mods, va_list arglist, int precision)
{
	int		len;
	char	*ret;

	len = get_len(mods);
	if (len == L)
		ret = ft_itoa_base((unsigned long)va_arg(arglist, unsigned long), 16);
	else if (len == LL)
		ret = ft_itoa_base((unsigned long long)
			va_arg(arglist, unsigned long long), 16);
	else if (len == J)
		ret = ft_itoa_base((uintmax_t)va_arg(arglist, uintmax_t), 16);
	else if (len == Z)
		ret = ft_itoa_base((unsigned long long)va_arg(arglist, size_t), 16);
	else if (len == HH)
		ret = ft_itoa_base((unsigned char)va_arg(arglist, unsigned long), 16);
	else if (len == H)
		ret = ft_itoa_base((unsigned short)va_arg(arglist, unsigned long), 16);
	else
		ret = ft_itoa_base((unsigned int)va_arg(arglist, unsigned int), 16);
	if (!ret)
		return (NULL);
	if (ret[0] == '0' && ret[1] == '\0' && precision == 0)
		ret[0] = 0;
	return (ret);
}

int			spec_up_x(char *mods, va_list arglist)
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
	if ((output[0] == 0 || output[0] == '0') &&
		output[1] == '\0' && checkthrough_for(mods, '#'))
		mods[get_indexof(mods, '#')] = '_';
	output = do_precision(output, precision);
	if (!output)
		return (0);
	output = do_minwidth(output, minwidth, mods, 'X');
	if (!output)
		return (0);
	output = strtoupper(output);
	retlen = printf_free(output);
	return (retlen);
}
