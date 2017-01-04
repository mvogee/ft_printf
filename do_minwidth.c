/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_minwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 21:18:22 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/16 21:18:24 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// minwidth includes the space modifier.
// minwidth includes the sign modifier.
// minwidth needs to deal with justification

static char	get_pad(char *mods)
{
	char	pad;

	pad = ' ';
	while (*mods++)
	{
		if (*mods == '-')
		{
			pad = ' ';
			break ;
		}
		if (*mods == '0')
			pad = '0';
	}
	if (checkthrough_for(mods, '.'))
		pad = ' ';
	return (pad);
}

// with right justify we know we dont have to deal with the 0 pad mod
// we still have to deal with the ' ' mod. it still goes in front of the precicion
static char	*do_justify_pad(char *original, int minwidth)
{
	char	*output;
	int		count;

	count = 0;
	output = (char*)malloc(sizeof(char) * minwidth + 1);
	if (!output)
		return (NULL);
	output[minwidth] = '\0';
	while (*original)
	{
		output[count] = *original;
		count++;
		original++;
	}
	while (count < minwidth)
	{
		output[count] = ' ';
		count++;
	}
	return (output);
}

// here we know we dont have right justify we just need to deal with the sign
// different possible signs are (space) + -
// only need to worry about the + and (space) signs a - sign will aleady be on
// the string when it is passed to the function
static char	*do_pad(char *original, int minwidth, char *mods, char spec)
{
	char	*output;
	char	pad;

	pad = get_pad(mods);
	output = (char*)malloc(sizeof(char) * minwidth + 1);
	if (!output)
		return (NULL);
	(void)original;
	(void)spec;

	return (output);
}
// the # modifier is done after precision but before the min width
// the # mod only effects the x and o specifiers
// we will need to deal with the space mod durring minwidth padding
char		*do_minwidth(char *original, int minwidth, char *mods, char spec)
{
	int		len;
	char	*output;
	char	*tmp;
// the whole signing part could be moved to a sepperate function if space is needed
	if ((spec == 'x' || spec == 'X' || spec == 'o' || spec == 'O') && checkthrough_for(mods, '#'))
		tmp = hexoct_sign(spec, original);
	else if (spec == 'd' || spec == 'D' || spec == 'i' || spec == 'u' || spec == 'U')
		tmp = do_sign(original, mods);
	else
		tmp = ft_strdup(original);
	len = ft_strlen(tmp);
	if (len < minwidth)
	{
		if (checkthrough_for(mods, '-'))
			output = do_justify_pad(tmp, minwidth); //working here
		else
			output = do_pad(tmp, minwidth ,mods, spec); //make me
	}
	else
		output = ft_strdup(tmp);
	if (!output)
			return (NULL);
	free(tmp);
	free(original);
	return (output);
}
