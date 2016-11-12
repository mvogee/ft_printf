/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:43:59 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/08 11:44:01 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

// typedef enum	e_flags
// {
// 	FLAG = 0,
// 	MIN_WIDTH = 1,
// 	PRECISION = 2,
// 	LENGTH_MOD = 3,
// }				t_flags;

typedef void (*dispatch_ptr) (char *, va_list);

void	exit_call(int reason);
void 	dispatch_c(char *format, va_list arglist);
void 	dispatch_d(char *format, va_list arglist);
void 	dispatch_i(char *format, va_list arglist);
void 	dispatch_o(char *format, va_list arglist);
void 	dispatch_pc(char *format, va_list arglist);
void 	dispatch_s(char *format, va_list arglist);
void 	dispatch_u(char *format, va_list arglist);
void 	dispatch_x(char *format, va_list arglist);
void 	dispatch_up_c(char *format, va_list arglist);
void 	dispatch_up_d(char *format, va_list arglist);
void 	dispatch_up_o(char *format, va_list arglist);
void 	dispatch_up_s(char *format, va_list arglist);
void 	dispatch_up_u(char *format, va_list arglist);
void 	dispatch_up_x(char *format, va_list arglist);

# endif
//"SsdDioOuUxXcC%"