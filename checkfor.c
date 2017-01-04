/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:19:30 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 11:19:31 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ALL FUNCTIONS RETURN 0 FOR ERROR 1 FOR SUCCESS 
*/

int		checkfor_specifier(char	c)
{
	const char *SPECIFIERS;
	int count;

	count= 0;
	SPECIFIERS  = "sSpdDioOuUxXcC%";
	while (SPECIFIERS[count])
	{
		if (SPECIFIERS[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkfor_flags(char c)
{
	const char *FLAGS;
	int count;

	count = 0;
	FLAGS  =  "hljz";
	while (FLAGS[count])
	{
		if (FLAGS[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkfor_modifiers(char c)
{
	const char *MODIFIERS;
	int count;

	count = 0;
	MODIFIERS = ".*#0-+ ";
	while (MODIFIERS[count])
	{
		if (MODIFIERS[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkfor_all(char c)
{
	const char *ALL_FRMAT_CHARS;
	int count;

	count = 0;
	ALL_FRMAT_CHARS = " 1234567890.*#-+ hljzsSpdDioOuUxXcC";
	while (ALL_FRMAT_CHARS[count])
	{
		if (ALL_FRMAT_CHARS[count] == c)
			return (1);
		count++;
	}
	return (0);
}

int		checkthrough_for(char *mods, char c)
{
	if (!mods)
		return (0);
	while (*mods)
	{
		if (*mods == c)
			return (1);
		mods++;
	}
	return (0);
}

