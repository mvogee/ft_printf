/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:35:00 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/10 17:35:02 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
// 0,+,#, ' ' flags should not work,

static void	start_flag(char *flag, char *output)
{
	if (*flag == ' ' || *flag == '+' || *flag == '#' || *flag == '0')
		exit_call(2);
	if (*flag == '-')
		perform_flags(*flag, output);
}

void 	dispatch_s(char *format, va_list arglist)
{
	write(1, "entered dispatch_s\n", 19);
	char *str;


	str = va_arg(arglist, char *);
	if (!str)
	{
		exit_call(2);
		return ;
	}
	while (*format != 's')
	{
		if (*format == '-' || *format == '+' || *format == ' ' ||
			*format == '#' || *format == '0')
			start_flag(format, str);
		format++;
	}
	while (*str)
	{
		write(1, *(&str), 1);
		str++;
	}
	(void)format;
	(void)arglist;
}
