/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:35:00 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/10 17:35:02 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void 	dispatch_c(char *format, va_list arglist)
{
	write(1, "entered dispatch_c\n", 19);
	(void)format;
	(void)arglist;
}


