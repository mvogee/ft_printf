NAME = ft_printf

SRCS = ft_printf.c \
		moveto.c	\
		parse_format.c \
		checkfor.c	\
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
		\
		libft_functions/ft_strsub.c \
		libft_functions/ft_itoa.c \
		libft_functions/ft_atoi.c \

OBJS = ft_printf.o \
		moveto.o	\
		parse_format.o \
		checkfor.o	\
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
		\
		ft_strsub.o \
		ft_itoa.o \
		ft_atoi.o \

CC = gcc

CFLAGS = -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(NAME) $(SRCS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
