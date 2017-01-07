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

typedef enum	e_len
{
	NONE = 0,
	HH = 1,
	H = 2,
	L = 3,
	LL = 4,
	J = 5,
	Z = 6
}				t_len;

//ft_printf.c
int		ft_printf(char *format, ...);
int		read_format(char *format, va_list arglist);
int		parse_format(char *format, va_list arglist);
int		printf_free(char *output);

//moveto.c
int		find_specifier_pos(char *format);
char	*print_moveto(char *format, int len);
char	*moveto_specifier(char *format);

//checkfor.c
int		checkfor_specifier(char	c);
int		checkfor_flags(char c);
int		checkfor_modifiers(char c);
int		checkfor_all(char c);
int		checkthrough_for(char *mods, char c);

//get_formats.c
int		get_precision(char *mods, va_list arglist);
int		get_minwidth(char *mods, va_list arglist);
int		get_justify(char *mods);
char	get_pad(char *mods);
int		get_indexof(char *str, char c);

//get args
int		get_len(char *mods);
int		make_short(int i);
char	*h_spec(va_list arglist);
char	*hh_spec(va_list arglist);

//do_precision
char	*do_precision(char	*output, int precision);
//do_minwidth
char	*do_minwidth(char *original, int minwidth, char *mods, char spec);
//do_signs.c
char	*do_sign(char *original, char *mods);
char	*hexoct_sign(char spec, char *original);
char	get_sign(char *original, char *mods);

//ft_uni_to_utf8.c
char		*ft_uni_utf8_char(wchar_t c);
char		*ft_uni_utf8_str(wchar_t *str);

//libft_functions
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
char	*ft_lltoa(long long int n);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_utoa(uintmax_t num);
char	*ft_itoa_base(uintmax_t n, int b);

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
int		spec_invalid(char *mods, int minwidth, char output);

#endif