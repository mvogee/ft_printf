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

char	*print_moveto(char *format, int len);
{
	write(1, format, len);
	return (foramt + len);
}

int		read_format(char *format, va_list arglist)
{
	int		totallen;
	int		count;

	count = 0;
	totallen = 0;
	while (format[count++])
	{
		if (format[count] == '%')
		{
			format = print_moveto(format, count);
			count = 0;
			totallen += dispatch_function(format, arglist);
			format = find_specifier(format);
		}
	}
	totallen += count;
	format = print_moveto(format, count);
	return (totallen);
}


int		ft_printf(char *format, ...)
{
	va_list		arglist;
	int			len;

	va_start(arglsit, format);
	len = 0;
	if (format)
		len = read_format(format, arglist);
	return (len);
}


int main(void)
{

}