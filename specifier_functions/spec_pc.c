/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:40:19 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:40:20 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		spec_pc(char *mods, va_list arglist)
{
	write(1, "spec_ \n", 7);
	(void)mods;
	(void)arglist;
	return (0);
}