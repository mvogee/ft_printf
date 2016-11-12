NAME = ft_printf

SRC = ft_printf.c \
		dispatches/dispatch_c.c \
		dispatches/dispatch_d.c \
		dispatches/dispatch_i.c \
		dispatches/dispatch_o.c \
		dispatches/dispatch_pc.c \
		dispatches/dispatch_s.c \
		dispatches/dispatch_u.c \
		dispatches/dispatch_x.c \
		dispatches/dispatch_up_c.c \
		dispatches/dispatch_up_d.c \
		dispatches/dispatch_up_o.c \
		dispatches/dispatch_up_s.c \
		dispatches/dispatch_up_u.c \
		dispatches/dispatch_up_x.c \

OBJS = ft_printf.o \
		dispatch_c.o \
		dispatch_d.o \
		dispatch_i.o \
		dispatch_o.o \
		dispatch_pc.o \
		dispatch_s.o \
		dispatch_u.o \
		dispatch_x.o \
		dispatch_up_c.o \
		dispatch_up_d.o \
		dispatch_up_o.o \
		dispatch_up_s.o \
		dispatch_up_u.o \
		dispatch_up_x.o \

HEADER = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all