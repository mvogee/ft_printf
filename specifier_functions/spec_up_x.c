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

int		spec_up_x(char *mods, va_list arglist)
{
	write(1, "spec_ \n", 7);
	(void)mods;
	(void)arglist;
	return (0);
}