/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:31:58 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 16:32:01 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		spec_s(char *mods, va_list arglist)
{
	write(1, "spec_ \n", 7);
	(void)mods;
	(void)arglist;
	return (0);
}