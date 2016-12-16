/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:25:31 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/15 16:25:32 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*pad_copy(char* original, int sign, int pad, int totallen)
{
	char	*ret;
	int		count;

	count = 0;
	ret = (char*)malloc(sizeof(char) * totallen);
		if (!ret)
			return (NULL);
	if (sign)
	{
		ret[0] = '-';
		count++;
	}
	while (count - sign < pad)
	{
		ret[count] = '0';
		count++;		
	}
	while (*original++)
	{
		ret[count] = *original;
		count++;
	}
	ret[totallen] = '\0';
	return (ret);
}

char	*do_precision(char	*output, int precision)
{
	int		len;
	int		count;
	int 	minussign;
	char	*retoutp;

	len = 0;
	count = 0;
	minussign = (output[0] == '-' ? 1 : 0);
	if (minussign)
		output++;
	len = ft_strlen(output);
	if (len < precision)
	{
		len = precision - len; // how many zeros we will add
		precision += 1 + minussign; // total lenght to allocate
		retoutp = pad_copy(output, minusssign, len, precision);

	}
	else
		retoutp = ft_strdup(output);
	free(output);
	return (retoutp);
}
