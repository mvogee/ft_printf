/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 23:40:21 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/07 23:40:22 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	if (size <= 0)
		return (NULL);
	mem = (unsigned char*)malloc(sizeof(mem) * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
