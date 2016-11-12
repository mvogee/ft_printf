/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:00:16 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/05 21:00:17 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// MAKE AN ARRAY OF FUNCTION POINTERS THAT CAN BE USED IN ACCORDENCE WITH AN ARRAY OF SPECIFIERS
dispatch_ptr	dispatch_array[14] = { dispatch_up_s, dispatch_s, dispatch_d,
	dispatch_up_d, dispatch_i, dispatch_o, dispatch_up_o, dispatch_u,
	dispatch_up_u, dispatch_x, dispatch_up_x, dispatch_c,
	dispatch_up_c, dispatch_pc};

// dispatch_array[0] = dispatch_up_s;
// dispatch_array[1] = dispatch_s;
// dispatch_array[2] = dispatch_d;
// dispatch_array[3] = dispatch_up_d;
// dispatch_array[4] = dispatch_i;
// dispatch_array[5] = dispatch_o;
// dispatch_array[6] = dispatch_up_o;
// dispatch_array[7] = dispatch_u;
// dispatch_array[8] = dispatch_up_u;
// dispatch_array[9] = dispatch_x;
// dispatch_array[10] = dispatch_up_x;
// dispatch_array[11] = dispatch_c;
// dispatch_array[12] = dispatch_up_c;
// dispatch_array[13] = dispatch_pc;
int total = 0; // potentailly need this global to hold the total number of characters printed? or just ft_strlen the end result string but in order to do that we would have to store the output string

void	exit_call(int reason)
{
	if (reason == 1)
	{
		write(1, "Incorrect usage\n", 16);
		exit(EXIT_FAILURE);
	}
	if (reason == 2)
	{
		write(1, "invalid flag for type\n", 22);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);
}

// this is just going to find the position of the specifier
int		parse_format(char *str, va_list arglist)
{
	char	*specifiers;
	int		count;
	int		found;
	int		ret;

	specifiers = "SsdDioOuUxXcC%";
	count = 0;
	found = 0;
	while (found >= 0 && str[found])
	{
		while(specifiers[count] && found >= 0)
		{
			ret = found;
			if (specifiers[count] == str[found])
			{
				found = -1;
				break ;
			}
			count++;
		}
		if (found < 0)
			break ;
		found++;
		count = 0;
	}
	(dispatch_array[count])(str, arglist); // dispatch
	return (ret + 1);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		arglist;

	va_start(arglist, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			fmt += parse_format((char*)fmt + 1, arglist) + 1;
		write(1, *(&fmt), 1);
		total++;
		fmt++;
	}
	va_end(arglist);
	return (total);
}

int main(void)
{
	(void)ft_printf("this %#10.10s string %s hi\n", "is a great", "that is in printf");
	return (0);
}
