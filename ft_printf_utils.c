/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:16:06 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/24 09:31:46 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdarg.h>

void ft_parse(char c, va_list *args) {
  if (c == 'c')
    ft_putchar(va_arg(*args, int));
  else if (c == 's')
    ft_putstr(va_arg(*args, char *));
  else if (c == 'p')
    ft_puthex(va_arg(*args, unsigned long int));
  else if (c == 'd')
    ft_putnbr(va_arg(*args, int));
  else if (c == 'i')
    ft_putnbr(va_arg(*args, int));
  else if (c == 'x')
    ft_puthex(va_arg(*args, unsigned int));
  else if (c == 'X')
    ft_puthex(va_arg(*args, unsigned int));
  else if (c == 'u')
    ft_putnbr(va_arg(*args, unsigned int));
  else if (c == '%')
    ft_putchar('%');
}

void ft_putchar(char c) { write(1, &c, 1); }

void ft_putstr(char *str) {
  int i;

  i = 0;
  while (str[i])
    ft_putchar(str[i++]);
}

void ft_putnbr(int n) {
  long int nb;
  char cnbr;

  nb = n;
  if (nb < 0) {
    nb = -nb;
    write(1, "-", 1);
  }
  if (nb > 9) {
    ft_putnbr(nb / 10);
    ft_putnbr(nb % 10);
  } else {
    cnbr = nb + 48;
    write(1, &cnbr, 1);
  }
}

void ft_puthex(unsigned long n) {
  char *hex;

  hex = "0123456789abcdef";
  if (n > 15) {
    ft_puthex(n / 16);
    ft_puthex(n % 16);
  } else
    ft_putchar(hex[n]);
}