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
#include <stdio.h>
// minwidth includes the space modifier.
// minwidth includes the sign modifier.
// minwidth needs to deal with justification

static char	*finish_pad(char *original, char *output, char pad, int minwidth)
{
	int		len;
	int		count;

	if ((output[0] == '-' || output[0] == '+' || output[0] == ' ' ||
		output[0] == '0') && output[1] != 'x' && output[1] != 'X')
		count = 1;
	else if (output[0] == '0' && (output[1] == 'x' || output[1] == 'X'))
		count = 2;
	else
		count = 0;
	len = minwidth - ft_strlen(original);
	while (count < minwidth && *original)
	{
		if (count < len)
			output[count] = pad;
		else
		{
			output[count] = *original;
			original++;
		}
		count++;
	}
	return (output);
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

static char	*pad_zero(char *original, int minwidth, char spec)
{
	char	*output;
	int		count;
	int		len;

	count = 0;
	if (!(output = (char*)malloc(sizeof(char) * minwidth + 1)))
		return (NULL);
	output[minwidth] = '\0';
	if (spec == 'x' || spec == 'X')
	{
		output[0] = original[0];
		output[1] = original[1];
		count += 2;
		original += 2;
	}
	else
	{
		output[count] = original[0];
		original++;
		count++;
	}
	len = minwidth - ft_strlen(original);
	output = finish_pad(original, output, '0', minwidth);
	return (output);
}

// here we know we dont have right justify we just need to deal with the sign
// different possible signs are (space) + -
// only need to worry about the + and (space) signs a - sign will aleady be on
// if we are padding with 0s we need to move any sign to the beggining
// the string when it is passed to the function
static char	*do_pad(char *original, int minwidth, char *mods, char spec)
{
	char	*output;
	char	pad;
	int		count;
	int		len;

	pad = get_pad(mods);
	count = 0;
	len = minwidth - ft_strlen(original);
	if (pad == '0' && (original[0] == '-' || original[0] == '+' ||
		original[0] == ' ' || checkthrough_for(mods, '#')))
		return (pad_zero(original, minwidth, spec));
	if (!(output = (char*)malloc(sizeof(char) * minwidth + 1)))
		return (NULL);
	output[minwidth] = '\0';
	output = finish_pad(original, output, pad, minwidth);
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
			output = do_justify_pad(tmp, minwidth); //minmal testing done :working
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

//replace finish_pad with this if proplems arise around finish_pad
	// while (count < minwidth && *original)
	// {
	// 	if (count < len)
	// 		output[count] = pad;
	// 	else
	// 	{
	// 		output[count] = *original;
	// 		original++;
	// 	}
	// 	count++;
	// }