
#include "printf.h"

char	get_sign(char *original, char *mods, char spec)
{
	if (spec == 'd' || spec == 'D' || spec == 'i')
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
	}
	else
		return (NULL);
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

char	*do_sign(char *original, int minwidth, char *mods, char spec)
{
	char	sign;
	char	*ret;

	sing = get_sign(original, mods, spec);
	if (sign && sing != '-')
		ret = ft_strjoin(sign, original);
	else
		ret = ft_strdup(original);
	return (ft_strjoin(original, sing));
}
