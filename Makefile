NAME = libftprintf.a 

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
SRCS = ft_printf.c ft_printf_utils.c
OBJECTS = $(SRCS:%.c=%.o)


all: $(NAME)

.o.c: $(SRCS)
	$(CC) $(CFLAGS) -L . -lftprintf -c $(SRCS)

$(NAME) : $(OBJECTS)
	$(AR) -rcs $@ $^

PHONY: clean fclean all re
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all