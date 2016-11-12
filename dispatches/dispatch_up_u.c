/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_up_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:39:57 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/10 17:39:59 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void 	dispatch_up_u(char *format, va_list arglist)
{
	write(1, "entered dispatch_up_u\n", 22);
		(void)format;
	(void)arglist;
}