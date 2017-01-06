/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:18:22 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/13 21:18:24 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// tested ft_printf, read_format, 

int		printf_free(char *output)
{
	int	len;

	len = ft_strlen(output);
	write(1, output, len);
	free(output);
	return(len);
}

int		parse_format(char *format, va_list arglist)
{
	int		ret;
	int		specpos;
	char	*mods;
	int		(*specifier_funciton)(char *, va_list);

	ret = 0;
	specpos = find_specifier_pos(format);
	if (specpos == -1)
		return (0);
	mods = (specpos == 0 ? NULL : ft_strsub(format, 0, specpos));
	specifier_funciton = dispatcher(format, specpos);
	ret = specifier_funciton(mods, arglist);
	if (mods)
		free(mods);
	return (ret);
}

int		read_format(char *format, va_list arglist)
{
	int		totallen;
	int		count;

	count = 0;
	totallen = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			format = print_moveto(format, count);
			format++;
			totallen += count;
			count = 0;
			totallen += parse_format(format, arglist);
			format = moveto_specifier(format);
		}
		if (*format)
			count++;
	}
	totallen += count; // (count > 0 ? count - 1: count);
	format = print_moveto(format, count);
	return (totallen);
}

int		ft_printf(char *format, ...)
{
	va_list		arglist;
	int			len;

	va_start(arglist, format);
	len = 0;
	if (format)
		len = read_format(format, arglist);
	va_end(arglist);
	return (len);
}


int main(void)
{
	int k;
	k  = ft_printf("%hhu", (unsigned char)-1);
	printf("\n%d\n", k);
	k  = printf("%hhu", (unsigned char)-1);
	printf("\n%d\n", k);
	return (0);
}