NAME = libftprintf.a

SRCS = ft_printf.c \
		moveto.c	\
		get_formats.c \
		checkfor.c	\
		get_args.c \
		do_precision.c \
		do_minwidth.c \
		do_signs.c \
		ft_uni_to_utf8.c \
		\
		specifier_functions/dispatcher.c \
		specifier_functions/spec_c.c \
		specifier_functions/spec_d.c \
		specifier_functions/spec_i.c \
		specifier_functions/spec_o.c \
		specifier_functions/spec_p.c \
		specifier_functions/spec_pc.c \
		specifier_functions/spec_s.c \
		specifier_functions/spec_u.c \
		specifier_functions/spec_up_c.c \
		specifier_functions/spec_up_d.c \
		specifier_functions/spec_up_o.c \
		specifier_functions/spec_up_s.c \
		specifier_functions/spec_up_u.c \
		specifier_functions/spec_up_x.c \
		specifier_functions/spec_x.c \
		specifier_functions/spec_invalid.c \
		\
		libft_functions/ft_strsub.c \
		libft_functions/ft_itoa.c \
		libft_functions/ft_atoi.c \
		libft_functions/ft_strlen.c \
		libft_functions/ft_isascii.c \
		libft_functions/ft_isalnum.c \
		libft_functions/ft_isdigit.c \
		libft_functions/ft_lltoa.c \
		libft_functions/ft_strdup.c \
		libft_functions/ft_strjoin.c \
		libft_functions/ft_utoa.c \
		libft_functions/ft_itoa_base.c \


OBJS = ft_printf.o \
		moveto.o	\
		get_formats.o \
		checkfor.o	\
		get_args.o \
		do_precision.o \
		do_minwidth.o \
		do_signs.o \
		ft_uni_to_utf8.o \
		\
		dispatcher.o \
		spec_c.o \
		spec_d.o \
		spec_i.o \
		spec_o.o \
		spec_p.o \
		spec_pc.o \
		spec_s.o \
		spec_u.o \
		spec_up_c.o \
		spec_up_d.o \
		spec_up_o.o \
		spec_up_s.o \
		spec_up_u.o \
		spec_up_x.o \
		spec_x.o \
		spec_invalid.o \
		\
		ft_strsub.o \
		ft_itoa.o \
		ft_atoi.o \
		ft_strlen.o \
		ft_isascii.o \
		ft_isalnum.o \
		ft_isdigit.o \
		ft_lltoa.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_utoa.o \
		ft_itoa_base.o \

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

.PHONY : clean

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
