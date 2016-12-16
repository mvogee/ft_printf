/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:52:28 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/14 15:52:29 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int get_dispatch(char speci)
{
	const char		*specs;
	int				id;

	id = 0;
	specs = "sSpdDioOuUxXcC%";
	while (specs[id] != speci)
		id++;
	return (id);
}

int (*dispatcher(char *format, int specpos))(char *, va_list)
{
	int				type;
	t_dispatch_ptr	dispatch_array[15];

	dispatch_array[0] = spec_s;
	dispatch_array[1] = spec_up_s;
	dispatch_array[2] = spec_p;
	dispatch_array[3] = spec_d;
	dispatch_array[4] = spec_up_d;
	dispatch_array[5] = spec_i;
	dispatch_array[6] = spec_o;
	dispatch_array[7] = spec_up_o;
	dispatch_array[8] = spec_u;
	dispatch_array[9] = spec_up_u;
	dispatch_array[10] = spec_x;
	dispatch_array[11] = spec_up_x;
	dispatch_array[12] = spec_c;
	dispatch_array[13] = spec_up_c;
	dispatch_array[14] = spec_pc;
	type = get_dispatch(*(format + specpos));
	return (dispatch_array[type]);
}
