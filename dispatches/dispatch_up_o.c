/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_up_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:39:57 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/10 17:39:59 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void 	dispatch_up_o(char *format, va_list arglist)
{
	write(1, "entered dispatch_up_o\n", 22);
		(void)format;
	(void)arglist;
}
