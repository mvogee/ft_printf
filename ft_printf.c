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
	return (len);
}

int		parse_format(char *format, va_list arglist)
{
	int		ret;
	int		specpos;
	char	*mods;
	int		(*specifier_funciton)(char *, va_list);

	ret = 0;
	specpos = find_specifier_pos(format);
	if ((specpos <= -1 || !checkfor_all(format[specpos]))) // dealing with 010Z cases
	{
		specpos *= (specpos < 0 ? -1 : 1);
		if ((checkfor_all(format[specpos]) == 0 && format[specpos] != '\0'))
		{
			mods = (!format[specpos] ? NULL : ft_strsub(format, 0, specpos));
			return (spec_invalid(mods, get_minwidth(mods, arglist),
				format[specpos]));
		}
	}
	if (!format[specpos])
		return (0);
	mods = (specpos == 0 ? NULL : ft_strsub(format, 0, specpos));
	specifier_funciton = dispatcher(format, specpos);
	ret += specifier_funciton(mods, arglist);
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
		if (*format && *format != '%')
			count++;
	}
	totallen += count;
	format = print_moveto(format, count);
	return (totallen);
}

/*
** chec_char_nulls
** this function is to catch for return length being wrong when a null
** character is given as an argument
** simply goes through all the args checking to see if they are a null char
*/

int				check_char_nulls(char *format, va_list arglist)
{
	int			ret;
	char		c;

	ret = 0;
	c = 'x';
	while (*format)
	{
		while (*format && *format != '%')
			format++;
		if (*format == '%')
			format = moveto_specifier(format);
		if (*format && (*format == 'c' || *format == 'C'))
		{
			c = va_arg(arglist, int);
			if (c == 0 || !c)
				ret++;
		}
		else
			(void)va_arg(arglist, long long int);
	}
	return (ret);
}

int		ft_printf(char *format, ...)
{
	va_list		arglist;
	va_list		copy;
	int			len;

	va_start(arglist, format);
	va_copy(copy, arglist);
	len = 0;
	if (format)
	{
		len = read_format(format, arglist);
		len += check_char_nulls(format, copy);
	}
	va_end(arglist);
	va_end(copy);
	return (len);
}

#include <locale.h>
#include <string.h>
int main(void)
{
	setlocale(LC_ALL, "");
	int k;
	k = ft_printf("%V%%%");
	printf("\n%d\n", k);
	k =	printf("@moulitest: %#.x %0#.0x", 1, 0);
	printf("\n%d\n", k);
	return (0);
}