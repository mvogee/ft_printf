/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_signs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:03:09 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/05 16:03:31 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	get_sign(char *original, char *mods)
{
	if (original[0] == '-')
		return ('-');
	else
	{
		if (checkthrough_for(mods, '+'))
			return ('+');
		else if (checkthrough_for(mods, ' '))
			return (' ');
	}
	return ('\0');
}

char	*hexoct_sign(char spec, char *original)
{
	char *ret;

	if (spec == 'X')
		ret = ft_strjoin("0X", original);
	else if (spec == 'x')
		ret = ft_strjoin("0x", original);
	else if (spec == 'o' || spec == 'O')
		ret = ft_strjoin("0", original);
	else
		ret = ft_strdup(original);
	return (ret);
}

char	*do_sign(char *original, char *mods)
{
	char	sign;
	char	*ret;
	char	*s;

	sign = get_sign(original, mods);
	if (sign != '-')
		s = (sign == '+' ? "+" : " ");
	else
		s = "-";
	if (sign && sign != '-')
		ret = ft_strjoin(s, original);
	else
		ret = ft_strdup(original);
	return (ret);
}
