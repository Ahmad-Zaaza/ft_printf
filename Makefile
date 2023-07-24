NAME = libftprintf.a 

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar


SRCS = ft_printf.c ft_printf_utils.c
SRCS_B = ft_printf_bonus.c ft_printf_utils_bonus.c utils/ft_atoi.c
OBJECTS = $(SRCS:%.c=%.o)
OBJECTS_B = $(SRCS_B:%.c=%.o)


all: $(NAME)

.o.c: $(SRCS) $(SRCS_B)
	$(CC) $(CFLAGS) -L . -lftprintf -c $(SRCS) $(SRCS_B)

$(NAME) : $(OBJECTS)
	$(AR) -rcs $@ $^

bonus: $(OBJECTS_B)
	$(AR) -rcs $(NAME) $^

PHONY: clean fclean all re bonus
clean:
	rm -f $(OBJECTS) $(OBJECTS_B)
fclean: clean
	rm -f $(NAME)
re: fclean all