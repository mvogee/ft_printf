#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//#define const char *SPECIFIERS = "sSpdDiOuUxXcC%"
//#define const char *FLAGS =  "hljz"
//#define const char *MODIFIERS = ".*#0-+ "
//#define const char *ALL_FRMAT_CHARS = "1234567890.*#-+ hljzsSpdDioOuUxXcC"

typedef int (*t_dispatch_ptr) (char *, va_list);

//ft_printf.c
int		ft_printf(char *format, ...);
int		read_format(char *format, va_list arglist);

//moveto.c
int		find_specifier_pos(char *format);
char	*print_moveto(char *format, int len);
char	*moveto_specifier(char *format);

//checkfor.c
int		checkfor_specifier(char	c);
int		checkfor_flags(char c);
int		checkfor_modifiers(char c);
int		checkfor_all(char c);

//libft_functions
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

//dispatcher
int 	get_dispatch(char speci);
int 	(*dispatcher(char *format, int specpos))(char *, va_list);
int		spec_c(char *mods, va_list arglist);
int		spec_d(char *mods, va_list arglist);
int		spec_i(char *mods, va_list arglist);
int		spec_o(char *mods, va_list arglist);
int		spec_p(char *mods, va_list arglist);
int		spec_pc(char *mods, va_list arglist);
int		spec_s(char *mods, va_list arglist);
int		spec_u(char *mods, va_list arglist);
int		spec_up_c(char *mods, va_list arglist);
int		spec_up_d(char *mods, va_list arglist);
int		spec_up_o(char *mods, va_list arglist);
int		spec_up_s(char *mods, va_list arglist);
int		spec_up_u(char *mods, va_list arglist);
int		spec_up_x(char *mods, va_list arglist);
int		spec_x(char *mods, va_list arglist);

#endif