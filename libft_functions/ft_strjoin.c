
#include "../ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	len = 0;
		while (*s1 && s1)
		{
			ret[len] = *s1;
			len++;
			s1++;
		}
	while (*s2 && s2)
	{
		ret[len] = *s2;
		len++;
		s2++;
	}
	return (ret);
}